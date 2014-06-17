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
/*!
 * \brief Główne okno programu Serwer.
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
     * \brief Otwarcie sesji. Polega na przydzieleniu adresu IP oraz jego wyświetleniu.
     */
    void openSession();
    /*!
     * \brief Metoda obsługująca nowe połączenie z serwerem.
     *
     * Dodaje nowego klienta do listy.
     */
    void newConnection();

    /*!
     * \brief Metoda służąca do odebrania wiadomości od klienta.
     */
    void newMessage();

    /*!
     * \brief Obsługa timera, decydującego o ruchach figur.
     */
    void on_timer();

    /*!
     * \brief Metoda obsługująca rozłączenie klienta z serwerem.
     */
    void clientDisconnected();

    /*!
     * \brief Rozpoczyna grę.
     */
    void on_pushButtonStart_clicked();


    /*!
     * \brief Zatrzymuje grę.
     */
    void on_pushButtonStop_clicked();

private:
    /*!
     * \brief Służy do zmiany poziomu.
     * \param i Numer poziomu.
     *
     * Jednocześnie zwalnia pamięć oraz przydziela ją nowo utworzonym figurom oraz odcnikom.
     */
    void zmienPoziom(int i);

    /*!
     * \brief Określa zwycięscę oraz wysyła informację o przegranej/wygranej klientom.
     */
    void koniecPoziomu(int);

    /*!
     * \brief Tworzenie ruchu figur, sterowanych przez klientów.
     */
    void ruchOdrzutowy(int, int);

    /*!
     * \brief Metoda odpowiedzialna za poruszanie się figur.
     */
    void ruchFigur();

    /*!
     * \brief Metoda odpowiedzialna za "zjadanie" figur o mniejszym polu.
     */
    void zjadanieMniejszych();

    /*!
     * \brief Zwalnia pamięć oraz usuwa odcniki z listy.
     */
    void usunOdicnki();

    /*!
     * \brief Zwalnia pamięć oraz usuwa figury z listy.
     */
    void usunFigury();

    /*!
     * \brief Zmienia dowolną figurę w inną.
     *
     * Kolejność zmian: Kolo->Kwadrat->Trojkat->Kolo.
     */
    void zmienFigure(Figura*);
    /*!
     * \brief
     * \return informację o liczbie graczy, którzy nie zostali "zjedzeni".
     */
    int zwrocLiczbeAktywnychGraczy(int &);


    Ui::MainWindow *ui;
    QTcpServer *server; //!< Pole, służące do obsługi serwera.
    QNetworkSession * networkSession;
    QList <QTcpSocket*> clients; //!< Lista klientów połączonych z serwerem.
    int ramkaPrzyblizania; //!< Określa zakres pola, na którym toczy się gra.
    QList <Figura*> listaFigur; //!< Lista wkaźników klasy Figura. Zawiera wszystkie rysowane figury.
    QList <Odcinek*> listaOdcinkow; //! Zawiera wszystkie odcinki, od których odbijają się figury.
    Poziomy poziomy; //!< Zawiera wszystkie poziomy.
    QTimer timer; //!< Służy do odmierzania czasu, po którym aktualizowana jest gra.
    int Ts; //!< Czas odmierzany przez timer.
    int aktualnyPoziom; //!< Informacja o numerze aktualnego poziomu.
    bool wyslanoKoniecPoziomu; //! Służy do określenia, czy do klientów została wysłana informacja o ukończeniu poziomu.


};



#endif // MAINWINDOW_H
