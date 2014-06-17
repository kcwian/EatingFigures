#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTime>
#include <QList>
#include "dialog.h"
#include "dialog2.h"
#include "figura.h"
#include "odcinek.h"




namespace Ui {
class MainWindow;
}

/*!
 * \brief Główne okno programu Klienta.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    enum {FIGURY,INFO,KONIEC,WYGRANA,PRZEGRANA,REMIS,ZMIANA}; //!< Typ wyliczeniowy, służący do identyfikacjy danych przesyłanych przez serwer.
    /*!
     * \brief Konstruktor
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
     * \brief Służy bezpośrednio do połączenia z serwerem.
     *
     * W przypadku udanego połączenia wyświetla komunikat "Connected"
     */
    void connectToServer(QString,int);

    /*!
     * \brief Służy do odbierania wiadomości z serwera.
     */
    void newMessage();

    /*!
     * \brief Wywołuje okno dialogowe, służące do połączenia z serwerem.
     */
    void on_pushButtonPolacz_clicked();
    /*!
     * \brief Służy do obsługi klawiatury. Każdą informację wysyła na serwer.
     */
    void keyPressEvent(QKeyEvent *);

    /*!
     * \brief Wysyła informację na serwer o tym, by zmienić poziom.
     */
    void zmienPoziomMessage();

private:
    /*!
     * \brief Lista wskaźników na klasę Figura. Pośredniczy w przesyłaniu figur między serwerem i klasą MyGLWidget.
     */
    QList <Figura*> listaFigur; // pośredniczy w przesyłaniu

    /*!
     * \brief  Lista wskaźników na klasę Odcinek. Pośredniczy w przesyłaniu odcinków między serwerem i klasą MyGLWidget.
     */
    QList <Odcinek*> listaOdcinkow;
    Ui::MainWindow *ui;
    /*!
     * \brief Gniazdo, służące do komunikacji z serwerem.
     */
    QTcpSocket *socket;
    Dialog *dialog;
    Dialog2 *dialog2;
    int wynik; //!< Przechowuje informację o ilości wygranych.


};

#endif // MAINWINDOW_H
