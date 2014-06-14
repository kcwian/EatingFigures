#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <QDataStream>

using namespace std;
/*!
 * \brief Klasa bazowa dla klas Kwadrat, Kolo, Trojkat.
 */
class Figura // Figury nie mają zmiennej Pole, jest ono wyliczane z rozmiaru
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
    void ustawKolor(float red, float green, float blue, float alpha);
    void ustawPredkoscX(float vx);
    void ustawPredkoscY(float vy);
    void ustawOmega(float v);
    float zwrocPredkoscX();
    float zwrocPredkoscY();
    float zwrocOmega();
    void zmienPolozenie(float dx, float dy);
    void zmienAlpha(float da);
    float zwrocPolozenieX();
    float zwrocPolozenieY();
    float zwrocAlpha();
  //  void ustawSpecjalnym(int);
    void ustawRozmiar(float);
    /*!
     * \brief Służy do rysowania figur w OpenGL.
     */
    virtual void rysuj() = 0;
    /*!
     * \brief S
     * \param x
     * \param y
     * \return
     */
    virtual bool czyNalezydoFigury(float x, float y) = 0; // do zmieniena na virtual i dokladniej
    virtual float zwrocRozmiar() = 0; // Rozmiar: Kolo-2*r, kwadrat - a, trojkat - a;
    virtual bool czyKolizja(Figura * druga) = 0; // zle
    virtual double zwrocodlegloscDoKolizji() = 0;
    virtual void zmienRozmiar(float) = 0;
    virtual float zwrocPole()=0;
    virtual void zmienPole(float) = 0;
    virtual int zwrocTyp()=0;
  //  virtual float

protected:
    float x,y;
    float r; // bok kwadratu, bok trojkata, promien okręgu
    float kolor[4];
    float predkosc[2];
    float omega, alpha;
    int typ;



};

#endif // FIGURA_H
