#ifndef KWADRAT_H
#define KWADRAT_H
#include "figura.h"

/*!
 * \brief Klasa służąca do rysowania kwadratu.
 */
class Kwadrat : public Figura
{
public:
    /*!
     * \brief Konstruktor domyślny
     */
    Kwadrat();
    /*!
     * \brief Konstruktor parametryczny
     * \param x_ Współrzędna X środka.
     * \param y_ Współrzędna Y środka.
     * \param a_ Długość boku.
     */
    Kwadrat(float x_, float y_, float a_); // srodek i dlugość boku
    ~Kwadrat();
    virtual void rysuj();
    virtual float zwrocRozmiar();
    virtual bool czyKolizja(Figura *druga);
    virtual void zmienRozmiar(float);
    virtual float zwrocPole();
    virtual void zmienPole(float);
    virtual double zwrocodlegloscDoKolizji();
    virtual int zwrocTyp();

private:
};

#endif
