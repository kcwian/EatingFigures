#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include <QtNetwork>
#include <QTimer>
#include "figura.h"
#include <poziomy.h>
#include <odcinek.h>
#include <QDataStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum {FIGURY,INFO};
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openSession();
    void newConnection();
    void newMessage();
    void on_timer();
    void clientDisconnected();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    void zmienPoziom(int i);
    void koniecPoziomu();
    void ruchOdrzutowy(int, int);
    void ruchFigur();
    void zjadanieMniejszych();
    void usunOdicnki();
    void usunFigury();

    Ui::MainWindow *ui;
    QTcpServer *server;
    QNetworkSession * networkSession;
    QList <QTcpSocket*> clients;

//    int wartoscOrtho;
    int ramkaPrzyblizania;
    GLfloat tlo[4];
    QList <Figura*> listaFigur;
    QList <Odcinek*> listaOdcinkow;
    Poziomy poziomy;
    QPointF lastPos;
    QTimer timer;
    int Ts;
    int aktualnyPoziom;



signals:
    void usunFigurySignal();
};



#endif // MAINWINDOW_H
