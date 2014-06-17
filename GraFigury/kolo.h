#ifndef KOLO_H
#define KOLO_H
#include <QGLWidget>
#include "figura.h"

/*!
 * \brief Klasa służąca do rysowania koła.
 */
class Kolo : public Figura
{

public:
    /*!
     * \brief Konstruktor domyślny
     */
    Kolo();
    /*!
     * \brief Konstruktor parametryczny
     * \param x_ Współrzędna X środka.
     * \param y_ Współrzędna Y środka.
     * \param r_ Promień koła.
     */
    Kolo(float x_, float y_, float r_);
    ~Kolo();

    virtual void rysuj();
    virtual float zwrocRozmiar();
    virtual bool czyKolizja(Figura *druga);
    virtual void zmienRozmiar(float);
    virtual float zwrocPole();
    virtual void zmienPole(float);
    virtual double zwrocodlegloscDoKolizji();
    virtual int zwrocTyp();

protected:

};

#endif // KOLO_H
