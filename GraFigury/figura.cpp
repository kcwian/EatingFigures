#include <cmath>
#include "figura.h"
#include <QTextStream>
#include <kolo.h>
#include <kwadrat.h>
#include <trojkat.h>


using namespace std;

Figura::Figura()
{

    x = 0;
    y = 0;

}

Figura::Figura(float x_, float y_)
{
    x = x_;
    y = y_;
    kolor[0] = (float) (rand()%101)/100;
    kolor[1] = (float) (rand()%101)/100;
    kolor[2] = (float) (rand()%101)/100;
    kolor[3] =  1;
    predkosc[0] = rand()%41-20;
    predkosc[1] = rand()%41-20;
    omega = rand()%60-30;
    alpha = 0;
    specjalny = 0;

}

Figura::~Figura()
{
}



float Figura::odleglosc()
{
    return sqrt(x*x+y*y);
}

float Figura::odleglosc(Figura *druga)
{
    float a = (druga->x - x)*(druga->x - x) + (druga->y - y)*(druga->y - y);
    return sqrt(a);
}

float Figura::odleglosc(float w, float z)
{
    float a = (w - x)*(w - x) + (z - y)*(z - y);
    return sqrt(a);
}

void Figura::ustawKolor(float red, float green, float blue, float alpha)
{
    kolor[0] = red;
    kolor[1] = green;
    kolor[2] = blue;
    kolor[3] = alpha;
}

void Figura::ustawPredkoscX(float vx)
{
    // ograniczenie predkosci
    if (vx > -120 && vx< 120)
    predkosc[0] = vx;
}

void Figura::ustawPredkoscY(float vy)
{
    if (vy > -120 && vy< 120)
    predkosc[1] = vy;
}

float Figura::zwrocPredkoscX()
{
    return predkosc[0];
}

float Figura::zwrocPredkoscY()
{
    return predkosc[1];
}

void Figura::zmienPolozenie(float dx, float dy)
{
    x += dx;
    y += dy;
}

float Figura::zwrocPolozenieX()
{
    return x;
}

float Figura::zwrocPolozenieY()
{
    return y;
}

void Figura::ustawOmega(float v)
{
    omega = v;
}

void Figura::zmienAlpha(float da)
{
    alpha += da;
    if(alpha > 360)
        alpha -= 360;
}

float Figura::zwrocOmega()
{
    return omega;
}

float Figura::zwrocAlpha()
{
    return alpha;
}

void Figura::ustawSpecjalnym(int typ)
{
    if(typ > 2 && typ < 10)
    specjalny = typ;
}


QDataStream & operator <<(QDataStream &stream, Figura* figura)  // nie wysyla informacji o typie specjalnym
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
    stream << figura->specjalny;
    stream << figura->typ;
    return stream;
}

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
    stream >> figura->specjalny;
    stream >> figura->typ;
    return stream;
}

QDataStream & operator <<(QDataStream &stream, QList <Figura*> &listaFigur)
{
    int rozmiarListy = listaFigur.size();
    stream << rozmiarListy; // Pierwszy element to dlugosc listy
    for(int i=0; i<rozmiarListy;i++)
    {
         stream << listaFigur.at(i)->zwrocTyp(); // Najpierw info o typie figury
        stream << listaFigur.at(i); // Korzysta z wcześniej przeciążonego operatora dla klasy Figura
    }
    return stream;
}

QDataStream & operator >>(QDataStream &stream, QList <Figura*> &listaFigur)
{

    int rozmiarListy;
    stream >> rozmiarListy;
    Figura *figura;
    int typFigury;

    for(int i=0; i<rozmiarListy; i++)
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


void Figura::ustawRozmiar(float value)
{
    r = value;
}
