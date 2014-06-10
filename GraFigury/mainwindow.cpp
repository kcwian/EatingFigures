#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QTextStream>
#include <QString>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    dialog = new Dialog(this);
    dialog2 = new Dialog(this);
    connect(socket,SIGNAL(readyRead()),SLOT(newMessage()));
    connect(dialog,SIGNAL(connectToServer(QString,int)),this,SLOT(connectToServer(QString,int)));
    //    ui->tableWidget->insertRow(1);
    //    ui->tableWidget->addAction(new QAction("Co tototo",this));
    //    ui->tableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("Gracz 2"));
    //   // ui->tableWidget->setA


    //    ui->tableWidget->setItem(0,0,new QTableWidgetItem("CO"));
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
    enum {FIGURY,INFO,KONIEC_POZIOMU};

    if (socket->isReadable())
    {


        QDataStream data(socket);
        int rodzajDanych;
        data >> rodzajDanych;

        switch(rodzajDanych)
        {
        case FIGURY:
        {
            for (int i=0; i<listaFigur.size();i++)
            {
                delete listaFigur.at(i);
            }
            listaFigur.clear();


            data >> listaFigur; // ma przydzieloną dynamicznie pamięć, którą trzeba zwolnić
            ui->widget->przeslijFigury(listaFigur);
            break;
        }
        case INFO:
        {
            for (int i=0; i<listaOdcinkow.size();i++)
            {
                delete listaOdcinkow.at(i);
            }
            listaOdcinkow.clear();


            int ramkaPrzyblizania, nrKlienta;
            data >> listaOdcinkow; // ma przydzieloną dynamicznie pamięć, którą trzeba zwolnić
            data >> ramkaPrzyblizania;
            data >> nrKlienta;
            ui->widget->przeslijInfo(listaOdcinkow,ramkaPrzyblizania,nrKlienta);
            break;
        }
        case KONIEC_POZIOMU:
            bool wygrana;
            data >> wygrana;
            QTextStream out(stdout);
            out << "działa" << endl;
            if(wygrana)
                if(!(dialog2->isVisible()))
                dialog2->show();
            else
                    if(!(dialog2->isVisible()))
                    dialog->show();
            break;

        }

      socket->readAll(); // WAŻNEEEE: dzięki temu nie opoźnia się gra  ?????
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
