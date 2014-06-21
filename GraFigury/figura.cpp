#include <cmath>
#include "figura.h"
#include <QTextStream>
#include <kolo.h>
#include <kwadrat.h>
#include <trojkat.h>

using namespace std;
/*!
 * \brief Konstruktor domyślny.
 */
Figura::Figura()
{

    x = 0;
    y = 0;
}

/*!
 * \brief Konstruktor parametryczny.
 * \param x_ Współrzędna x środka figury.
 * \param y_ Współrzędna y środka figury.
 */
Figura::Figura(float x_, float y_)
{
    x = x_;
    y = y_;
    kolor[0] = (float) (rand()%101)/100;
    kolor[1] = (float) (rand()%101)/100;
    kolor[2] = (float) (rand()%101)/100;
    kolor[3] =  1;
    predkosc[0] = rand()%21-10;
    predkosc[1] = rand()%21-10;

    omega = rand()%60-30;
    alpha = 0;

}

/*!
 * \brief Destruktor.
 */
Figura::~Figura()
{
}


/*!
 * \brief
 * \return odległość figury od środka układu współrzędnych.
 */
float Figura::odleglosc()
{
    return sqrt(x*x+y*y);
}

/*!
 * \brief
 * \param druga Figura, od której środka mierzona jest odległość.
 * \return odległość między środkami dwóch figur.
 */
float Figura::odleglosc(Figura *druga)
{
    float a = (druga->x - x)*(druga->x - x) + (druga->y - y)*(druga->y - y);
    return sqrt(a);
}

/*!
 * \brief
 * \param xp Współrzędna x punktu.
 * \param yp Współrzędna y punktu.
 * \return Oblicza odległość figury od punktu.
 */
float Figura::odleglosc(float xp, float yp)
{
    float a = (xp - x)*(xp - x) + (yp - y)*(yp- y);
    return sqrt(a);
}

/*!
 * \brief Ustawia kolor figury (0-1)
 * \param red Wartość składowej czerwonej.
 * \param green Wartość składowej zielonej.
 * \param blue Wartość składowej niebieskiej.
 * \param alpha Wartość składowej alpha.
 */
void Figura::ustawKolor(float red, float green, float blue, float alpha)
{
    kolor[0] = red;
    kolor[1] = green;
    kolor[2] = blue;
    kolor[3] = alpha;
}

/*!
 * \brief Ustawia prędkość poruszania się figury w kierunku poziomym.
 * \param vx Wartość prędkości.
 */
void Figura::ustawPredkoscX(float vx)
{
    // ograniczenie predkosci
    if (vx > -120 && vx< 120)
    predkosc[0] = vx;
}

/*!
 * \brief Ustawia prędkość poruszania się figury w kierunku pionowym
 * \param vy Wartość prędkości.
 */
void Figura::ustawPredkoscY(float vy)
{
    if (vy > -120 && vy< 120)
    predkosc[1] = vy;
}

/*!
 * \brief
 * \return wartość składowej poziomej prędkości figury.
 */
float Figura::zwrocPredkoscX()
{
    return predkosc[0];
}

/*!
 * \brief
 * \return wartość składowej pionowej prędkości figury.
 */
float Figura::zwrocPredkoscY()
{
    return predkosc[1];
}

/*!
 * \brief Zmienia położenie figury.
 * \param dx Zmiana położenia na osi poziomej.
 * \param dy Zmiana położenia na osi pionowej.
 */
void Figura::zmienPolozenie(float dx, float dy)
{
    x += dx;
    y += dy;
}

/*!
 * \brief
 * \return współrzędną X położenia środka figury.
 */
float Figura::zwrocPolozenieX()
{
    return x;
}
/*!
 * \brief Figura::zwrocPolozenieY
 * \return współrzędną Y położenia środka figury.
 */
float Figura::zwrocPolozenieY()
{
    return y;
}

/*!
 * \brief Ustawia wartość prędkości kątowej figury.
 * \param v Wartość prędkośći kątowej.
 */
void Figura::ustawOmega(float v)
{
    omega = v;
}

/*!
 * \brief Zmienia wartość kąta obrotu figury.
 * \param da Zmiana kąta.
 */
void Figura::zmienAlpha(float da)
{
    alpha += da;
    if(alpha > 360)
        alpha -= 360;
}

/*!
 * \brief
 * \return wartość prędkości kątowej figury.
 */
float Figura::zwrocOmega()
{
    return omega;
}

/*!
 * \brief
 * \return aktualny kąt obrotu figury.
 */
float Figura::zwrocAlpha()
{
    return alpha;
}


/*!
 * \brief Przeciążony operator, służący do przesyłania figur przez strumień.
 */
QDataStream & operator <<(QDataStream &stream, Figura* figura)
{

    stream << figura->x;
    stream << figura->y;
    stream << figura->r;
    stream << figura->kolor[0];
    stream << figura->kolor[1];
    stream << figura->kolor[2];
    stream << figura->kolor[3];
    stream << figura->predkosc[0];
    stream << figura->predkosc[1];
    stream << figura->alpha;
    stream << figura->omega;
    stream << figura->typ;
    return stream;
}

/*!
 * \brief Operator służący do wczytywania obiektu klasy Figura z strumienia.
 */
QDataStream & operator >>(QDataStream &stream, Figura *figura)
{

    stream >> figura->x;
    stream >> figura->y;
    stream >> figura->r;
    stream >> figura->kolor[0];
    stream >> figura->kolor[1];
    stream >> figura->kolor[2];
    stream >> figura->kolor[3];
    stream >> figura->predkosc[0];
    stream >> figura->predkosc[1];
    stream >> figura->alpha;
    stream >> figura->omega;
    stream >> figura->typ;
    return stream;
}

/*!
 * \brief Operator służący do przesyłania listy figur przez strumień.
 */
QDataStream & operator <<(QDataStream &stream, QList <Figura*> &listaFigur)
{
    int rozmiarListy = listaFigur.size();
    stream << rozmiarListy; // Pierwszy element to długość listy
    for(int i=0; i<rozmiarListy;i++)
    {
         stream << listaFigur.at(i)->zwrocTyp(); // Informacja o typie figury
        stream << listaFigur.at(i); // Korzysta z wcześniej przeciążonego operatora dla klasy Figura
    }
    return stream;
}

/*!
 * \brief Operator służący do wczytywania listy figur z strumienia.
 *
 * Przydziela dynamicznie pamięć, którą należy zwolnić.
 */
QDataStream & operator >>(QDataStream &stream, QList <Figura*> &listaFigur)
{

    int rozmiarListy;
    stream >> rozmiarListy;
    Figura *figura;
    int typFigury;

    for(int i=0; i<rozmiarListy;i++)
    {
         stream >> typFigury;
        switch(typFigury)
        {
        case Figura::KOLO:

            figura = new Kolo;
            break;
        case Figura::KWADRAT:
            figura = new Kwadrat;
            break;
        case Figura::TROJKAT:
            figura = new Trojkat;
            break;
        }

       stream >> figura;
       listaFigur.append(figura);
    }
    return stream;

}


/*!
 * \brief Ustawia rozmiar figury.
 *
 * Koło - promień,
 * Kwadrat - długość boku,
 * Trojkat - długość boku.
 */
void Figura::ustawRozmiar(float value)
{
    r = value;
}

