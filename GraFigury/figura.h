#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <QDataStream>

using namespace std;
/*!
 * \brief Klasa bazowa dla klas: Kwadrat, Kolo, Trojkat.
 */
class Figura
{

    friend QDataStream & operator <<(QDataStream &stream, Figura *figura);
    friend QDataStream & operator >>(QDataStream &stream, Figura *figura);
    friend QDataStream & operator <<(QDataStream &stream, QList <Figura*> &listaFigur);
    friend QDataStream & operator >>(QDataStream &stream, QList <Figura*> &listaFigur);
public:
    Figura();
    Figura(float x_, float y_); 
    virtual ~Figura();
    enum {KOLO, KWADRAT, TROJKAT};
    float odleglosc();
    float odleglosc(Figura *druga);
    float odleglosc(float, float);
    void ustawRozmiar(float);
    float zwrocPredkoscX();
    float zwrocPredkoscY();
    void ustawPredkoscX(float vx);
    void ustawPredkoscY(float vy);
    void zmienPolozenie(float dx, float dy);
    float zwrocPolozenieX();
    float zwrocPolozenieY();
    void ustawOmega(float v);
     float zwrocOmega();
    void zmienAlpha(float da);
    float zwrocAlpha();
     void ustawKolor(float red, float green, float blue, float alpha);
    /*!
     * \brief Służy do rysowania figur w OpenGL.
     */
    virtual void rysuj() = 0;
    /*!
     * \brief
     *
     * Kolo - promień.
     * Kwadrat - długość boku.
     * Trojkat - długość boku.
     * \return rozmiar figury.
     */
    virtual float zwrocRozmiar() = 0; // Rozmiar: Kolo-2*r, kwadrat - a, trojkat - a;

    /*!
     * \brief Sprawdza czy nastąpiła kolizja dwóch figur.
     * \param druga Figura, z którą sprawdzana jest kolizja.
     * \return prawdę, gdy wystąpiła kolizja.
     */
    virtual bool czyKolizja(Figura * druga) = 0;

    /*!
     * \brief
     * \return promień kolizji figury.
     *
     * Promień kolizji:
     * Koło - promień.
     * Kwadrat - średnia arytmetyczna z długości połowy przekątnej oraz połowy boku.
     * Trojkat - połowa wysokości.
     */
    virtual double zwrocodlegloscDoKolizji() = 0;

    /*!
     * \brief Zmienia rozmiar figury.
     */
    virtual void zmienRozmiar(float) = 0;

    /*!
     * \brief
     * \return pole figury.
     */
    virtual float zwrocPole()=0;

    /*!
     * \brief Służy do zmiany pola figury. Jednocześnie oblicza nowy rozmiar.
     */
    virtual void zmienPole(float) = 0;

    /*!
     * \brief
     * \return informację, czy dana figura to Kolo, Kwadrat czy Trojkat.
     */
    virtual int zwrocTyp()=0;
  //  virtual float

protected:

    float x; //!< Współrzędna X położenia środka figury.
    float y; //!< Współrzędna Y położenia środka figury.
    float r; //!< Rozmiar figury.
    float kolor[4]; //!< Rozmiar figury.
    float predkosc[2]; //!< Rozmiar figury.
    float omega;//!< Prędkość kątowa figury.
    float alpha; //!< Aktualny kąt obrotu figury.
    int typ; //!< Typ figury.



};

#endif // FIGURA_H
