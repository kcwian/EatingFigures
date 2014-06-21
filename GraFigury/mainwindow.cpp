#include <ui_mainwindow.h>
#include <mainwindow.h>
#include <QList>
#include <QTextStream>
#include <QString>
#include <QKeyEvent>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wynik = 0;
    socket = new QTcpSocket(this);
    dialog = new Dialog(this);
    dialog2 = new Dialog2(this);
    connect(socket,SIGNAL(readyRead()),SLOT(newMessage()));
    connect(dialog2,SIGNAL(zmienPoziom()),this,SLOT(zmienPoziomMessage()));
    connect(dialog,SIGNAL(connectToServer(QString,int)),this,SLOT(connectToServer(QString,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectToServer(QString ip,int port)
{
    socket->abort();
    socket->connectToHost(ip,port);
    socket->waitForConnected(10);
    if(dialog->isVisible() && (socket->state() != QAbstractSocket::UnconnectedState))
    {
        dialog->ustawWiadomosc(QString("Connected"));
    }

}

void MainWindow::newMessage()
{
    if (socket->isReadable())
    {


        QDataStream data(socket);
        int rodzajDanych;
        data >> rodzajDanych;

        switch(rodzajDanych)
        {
        case FIGURY:
        {
            // Zwolnienie pamięci
            for (int i=0; i<listaFigur.size();i++)
            {
                delete listaFigur.at(i);
            }
            listaFigur.clear();


            data >> listaFigur;
            ui->widget->przeslijFigury(listaFigur);
            break;
        }
        case INFO:
        {
            dialog2->hide();

            // Zwolnienie pamięci
            for (int i=0; i<listaOdcinkow.size();i++)
            {
                delete listaOdcinkow.at(i);
            }
            listaOdcinkow.clear();


            int ramkaPrzyblizania, nrKlienta;
            data >> listaOdcinkow;
            data >> ramkaPrzyblizania;
            data >> nrKlienta;
            ui->widget->przeslijInfo(listaOdcinkow,ramkaPrzyblizania,nrKlienta);
            break;
        }
        case KONIEC:
        {
            int wygrana;
            data >> wygrana;
            switch(wygrana)
            {
            case PRZEGRANA:
                dialog2->ustawWiadomosc("Przegrałeś\n\nWciśnij OK aby kontynować");
                break;
            case WYGRANA:
                dialog2->ustawWiadomosc("Wygrałeś\n\nWciśnij OK aby kontynować");
             ui->labelWynik->setText(QString::number(wynik+=1));
                break;
            case REMIS:
                dialog2->ustawWiadomosc("Remis\n\nWciśnij OK aby kontynować");
                break;
            }
             dialog2->adjustSize();
            dialog2->show();

        }

        }
    }


    ui->widget->updateGL();
}



void MainWindow::on_pushButtonPolacz_clicked()
{

    dialog->show();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{


    switch(event->key())
    {
    case Qt::Key_Plus:
        ui->widget->zmienOrtho(-2);
        break;
    case Qt::Key_Minus:
        ui->widget->zmienOrtho(2);

        break;
    default:
    {
        QDataStream data(socket);
        if(socket->isWritable())
            data << event->key();
        break;
    }

    }

}

void MainWindow::zmienPoziomMessage()
{
    if(socket->isWritable())
    {
    QDataStream data(socket);
        data << ZMIANA;
    }
}
