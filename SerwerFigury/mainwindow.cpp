#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <figura.h>
#include <QKeyEvent>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QNetworkConfigurationManager manager;
    aktualnyPoziom = 0;
    if(manager.capabilities()&QNetworkConfigurationManager::NetworkSessionRequired) // zalezne od systemu
    {
        QNetworkConfiguration configuration = manager.defaultConfiguration();
        networkSession = new QNetworkSession(configuration,this);
        connect(networkSession, SIGNAL(opened()),this, SLOT(openSession()));
        networkSession->open(); // w sygnale po otwarciu sesji, obslugujemy
    }
    else
    {
        openSession();
    }

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    Ts=60;
    timer.setInterval(Ts);
    connect(&timer,SIGNAL(timeout()),this,SLOT(on_timer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::openSession()
{
    server = new QTcpServer(this); // tworzymy server
    if(!server->listen()) // uruchamiamy server, dziala niezaleznie
    {
        //QMessageBox::critical()
        close();
        return;
    }
    QString ipAddress;
    QList <QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i< ipAddressesList.size(); ++i)
    {

        if(ipAddressesList.at(i)!= QHostAddress::LocalHost // szuka adresu zewnÄ™trznego
                && ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

        ui->labelIP->setText("IP: " + ipAddress);
        ui->labelPort->setText("Port: " + QString::number(server->serverPort()));
    }


}

void  MainWindow::newConnection()
{

    timer.stop();
    QTcpSocket * newSocket = server ->nextPendingConnection();
    if(newSocket)
    {
        clients.append(newSocket);
        connect(newSocket,SIGNAL(readyRead()),this,SLOT(newMessage()));
        connect(newSocket,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
        ui->lineEditServer->clear();
        ui->lineEditServer->setText(QString::number(clients.size()) + " Player(s)");


    }

}

void MainWindow::newMessage()
{
    if(!(timer.isActive()))
        return;
    int key;
    for (int i=0; i < clients.size(); i++)
    {
        if (clients.at(i)->isReadable())
        {
            QDataStream data(clients.at(i));
            data >> key;
            if(key == -22) // Zmiana poziomu
            {
                QTextStream out(stdout);
                out << "tak232" << endl;
                wyslanoKoniecPoziomu = 0;
                zmienPoziom(aktualnyPoziom+1);
            }
            else if(key == Qt::Key_Up || key == Qt::Key_Down || key == Qt::Key_Left || key == Qt::Key_Right )
                ruchOdrzutowy(key,i);

        }
        clients.at(i)->readAll();

    }
}


void MainWindow::on_timer()
{

    // animacjaPrzyblizania();
    for (int i = 0; i<listaFigur.size(); i++)
    {
        for(int j=0; j<listaOdcinkow.size();j++)
        {
            listaOdcinkow.at(j)->czyKolizja(listaFigur.at(i));
        }
    }

    ruchFigur();
    zjadanieMniejszych();

    for (int i=0; i< clients.size(); i++)
    {
        QTcpSocket *tmp = clients.at(i);
        // if(tmp->isWritable())

        if(tmp->isWritable())
        {

            QDataStream data(tmp);
            data << FIGURY;
            data << listaFigur;

        }
    }

}


void MainWindow::ruchFigur()
{
    for(int i=0; i<listaFigur.length(); i++)
    {
        Figura *tmp = listaFigur.at(i);
        tmp->zmienPolozenie(Ts*tmp->zwrocPredkoscX()/1000,Ts*tmp->zwrocPredkoscY()/1000);
        tmp->zmienAlpha(Ts*tmp->zwrocOmega()/1000);
        QTextStream out(stdout);

        float x=tmp->zwrocPolozenieX(), y=tmp->zwrocPolozenieY(), d = tmp->zwrocodlegloscDoKolizji();
        if(x>=ramkaPrzyblizania+d || x<=-ramkaPrzyblizania-d || y>=ramkaPrzyblizania+d || y<=-ramkaPrzyblizania-d )// ??
        {
            if( i < clients.size() )
            {
                timer.stop();
                //zmienPoziom(aktualnyPoziom);
            }
            else
            {
                delete tmp;
                listaFigur.removeAt(i);
            }
        }

    }
}


void MainWindow::zjadanieMniejszych()
{
    // zjadanie mniejszych
    int k=1;
    if(listaFigur.length()>1)
    {
        for(int i=0; i<listaFigur.length()-1; i++)
        {
            Figura *tmp1 = listaFigur.at(i);
            for (int j=k;j<listaFigur.length();j++)
            {
                Figura *tmp2 = listaFigur.at(j);
                if(tmp1->czyKolizja(tmp2))
                {
                    if(tmp1->zwrocPole() >= tmp2->zwrocPole())
                    {
                        // if(tmp1->zwrocRozmiar() < 30) // maksymalny rozmiar
                        tmp1->zmienPole(+tmp2->zwrocPole()/4); // szybkosc zjadania
                        tmp2->zmienPole(-tmp2->zwrocPole()/4);
                    }
                    else
                    {
                        tmp1->zmienPole(-tmp1->zwrocPole()/4);
                        //if(tmp2->zwrocRozmiar() < 30)
                        tmp2->zmienPole(+tmp1->zwrocPole()/4);

                    }
                }

            }
            k++;

        }
        // jeśli Cię zjadło

        //        if (listaFigur.at(0)->zwrocRozmiar() < 0.5)
        //        {
        //            listaFigur.clear();
        //            usunFigurySlot();
        //            sterowana = new Kwadrat(-30,20,10);
        //            listaFigur.append(sterowana);

        //        }

        //osobna petla do usuwania
        float sumaPol = 0;
        for (int i=0; i < listaFigur.length(); i++)
        {

            Figura *tmp = listaFigur.at(i);
            sumaPol += tmp->zwrocPole();
            if (tmp->zwrocPole() <= 0.25) // rozmiar, czy pole?
            {

                if(i<clients.size())
                {
                    tmp->ustawRozmiar(0);
                    tmp->ustawPredkoscX(0);
                    tmp->ustawPredkoscY(0);
                }
                else
                {
                    delete listaFigur.at(i);
                    listaFigur.removeAt(i);
                }
            }
        }

        // Sprawdzanie czy koniec poziomu - musi być jeden aktywny gracz i miec pole większe niż suma pól pozostałych figur
        int liczbaAktywnychGraczy=0, graczAktywny = -1, tmp = -1;
        for(int i=0;i < clients.size();i++)
        {
            if(listaFigur.at(i)->zwrocPole()>0.25)
            {
                liczbaAktywnychGraczy++;
            }
            if(liczbaAktywnychGraczy == 1)
            {
                tmp = i;
            }
        }
        if(liczbaAktywnychGraczy == 1)
        {
            graczAktywny = tmp;
        }
        if(graczAktywny !=-1 && listaFigur.at(graczAktywny)->zwrocPole() > sumaPol-listaFigur.at(graczAktywny)->zwrocPole())
        {
            koniecPoziomu(graczAktywny);
        }
        else if(graczAktywny == -1)
        {
            koniecPoziomu(-1);
        }

        // zrobić warunek konca poziomu - zjeść przeciwnika, czy wszystkich ?



    }
}


void MainWindow::usunFigury()
{
    for (int i=0; i<listaFigur.length(); i++)
    {
        delete listaFigur.at(i);
    }
    listaFigur.clear();
}

void MainWindow::usunOdicnki()
{
    for (int i=0; i<listaOdcinkow.size(); i++)
    {
        delete listaOdcinkow.at(i);
    }
    listaOdcinkow.clear();
}

void MainWindow::zmienPoziom(int i)
{

    timer.stop();
    usunFigury();
    usunOdicnki();
    poziomy.inicjalizuj(i,ramkaPrzyblizania,listaFigur,listaOdcinkow,clients.size());
    aktualnyPoziom = i;

    // wysyłanie danych o poziomie
    for (int i=0; i< clients.size(); i++)
    {
        QTcpSocket *tmp = clients.at(i);
        if(tmp->isWritable())
        {
            QDataStream data(tmp);
            data << INFO;
            data << listaOdcinkow;
            data << ramkaPrzyblizania;
            data << i;

        }
    }
    wyslanoKoniecPoziomu = 0;
    zmiana = 0;
    timer.start(Ts);

}

void MainWindow::clientDisconnected()
{

    for (int i=0; i<clients.size(); i++)
    {
        if (clients.at(i)->state() != QAbstractSocket::ConnectedState)
        {
            clients.removeAt(i);
            ui->lineEditServer->clear();
            ui->lineEditServer->setText(QString::number(clients.size()) + " Player(s)");
        }
    }
    timer.stop();

}

void MainWindow::ruchOdrzutowy(int key, int i)
{

    Figura* sterowana = listaFigur.at(i);
    if(sterowana->zwrocPole()*0.1 < 0.001)
        return;
    float sVx = sterowana->zwrocPredkoscX();
    float sVy = sterowana->zwrocPredkoscY();
    Figura *nowa = 0;
    float dN = sterowana->zwrocodlegloscDoKolizji() + 1; // w tej odleglosc pojawi się nowa ,+1 -

    switch(sterowana->zwrocTyp())
    {
    case Figura::KWADRAT:
    {
        nowa = new Kwadrat(sterowana->zwrocPolozenieX(),sterowana->zwrocPolozenieY(),1);
        break;
    }
    case Figura::KOLO:
    {

        nowa = new Kolo(sterowana->zwrocPolozenieX(),sterowana->zwrocPolozenieY(),1);
        break;
    }
    case Figura::TROJKAT:
    {
        nowa = new Trojkat(sterowana->zwrocPolozenieX(),sterowana->zwrocPolozenieY(),1);
        break;
    }
    }

    listaFigur.append(nowa);
    float dPole = sterowana->zwrocPole()*0.05; // 5% figury
    sterowana->zmienPole(-dPole);
    nowa->zmienPole(-(nowa->zwrocPole() - dPole)); // domyślnie nowa ma rozmiar 1, a chce żeby miała pole dPole // można dopisać funkcje ustawPole


    switch(key)
    {
    case Qt::Key_Up:

        sterowana->ustawPredkoscY(sVy-2); // kolejnosc
        nowa->zmienPolozenie(0,dN);
        nowa->ustawPredkoscX(sVx);
        nowa->ustawPredkoscY(sVy + 6); //sc kolejno // stala prędkość wzgl sterowanej
        break;

    case Qt::Key_Down:

        sterowana->ustawPredkoscY(sVy+2);
        nowa->zmienPolozenie(0,-dN);
        nowa->ustawPredkoscX(sVx);
        nowa->ustawPredkoscY(sVy-6);

        break;
    case Qt::Key_Right:
        sterowana->ustawPredkoscX(sVx-2);
        nowa->zmienPolozenie(dN,0);
        nowa->ustawPredkoscX(sVx+6);
        nowa->ustawPredkoscY(sVy);


        break;
    case Qt::Key_Left:
        sterowana->ustawPredkoscX(sVx+2);
        nowa->zmienPolozenie(-dN,0);
        nowa->ustawPredkoscX(sVx-6);
        nowa->ustawPredkoscY(sVy);

    }

}


void MainWindow::on_pushButtonStart_clicked()
{
    int nrPoziomu = ui->comboBox->currentIndex();
    zmienPoziom(nrPoziomu);
    timer.start(Ts);
}

void MainWindow::on_pushButtonStop_clicked()
{
    timer.stop();
}

void MainWindow::koniecPoziomu(int graczAktywny)
{
    enum {FIGURY,INFO,KONIEC_POZIOMU};
    if(wyslanoKoniecPoziomu != 1) // w wiadomosci zwrotnej ustawić na 0
    {
        wyslanoKoniecPoziomu = 1;
        timer.stop();
        for (int i=0; i<clients.size();i++)
        {
            QTcpSocket *tmp = clients.at(i);
            if(tmp->isWritable())
            {
                QDataStream data(tmp);
                data << KONIEC_POZIOMU;
                if(clients.size() == 1 && graczAktywny == -1)
                    data << 0; // przegrana
                else if(clients.size() > 1 && graczAktywny == -1)
                    data << 2; // remis;
                else
                {
                    if (i != graczAktywny)
                    {
                        data << 0; // Przegrana
                        QTextStream out(stdout);
                        out << "Przegal" << endl;
                    }
                    else
                        data << 1; // Wygrana
                }

            }
        }
        timer.start(Ts);
    }

    //    if(zmiana= true)
    //        zmienPoziom(aktualnyPoziom+1);
}
