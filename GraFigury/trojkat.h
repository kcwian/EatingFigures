#ifndef TROJKAT_H
#define TROJKAT_H
#include "figura.h"
#include <QGLWidget>

/*!
 * \brief Klasa służąca do rysowania trójkąta.
 */
class Trojkat : public Figura
{
public:
    /*!
     * \brief Konstruktor domyślny
     */
    Trojkat();
    /*!
     * \brief Konstruktor parametryczny
     * \param x_ Współrzędna X środka.
     * \param y_ Współrzędna Y środka.
     * \param a_ Długość boku.
     */
    Trojkat(float x_, float y_, float a_);
    ~Trojkat();
    virtual void rysuj();
    virtual float zwrocRozmiar();
    virtual bool czyKolizja(Figura *druga);
    virtual void zmienRozmiar(float);
    virtual float zwrocPole();
    virtual double zwrocodlegloscDoKolizji();
    virtual void zmienPole(float);
    virtual int zwrocTyp();

private:

};

#endif
