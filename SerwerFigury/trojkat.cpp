#include "trojkat.h"
#include <cmath>

Trojkat::Trojkat()
{
    r = 0;
}

Trojkat::Trojkat(float x_, float y_, float a_)
    : Figura(x_,y_)
{
    r = a_;
    typ = TROJKAT;
}

Trojkat::~Trojkat()
{
}

void Trojkat::rysuj()
{
    glLoadIdentity();
    glTranslatef(x,y,0); // ma znaczenie
    glRotatef(alpha,0,0,1); // kolejnosc
    glColor4fv(kolor);
    glBegin(GL_POLYGON);
    glVertex2f(-r/2,-r*1.73/6);
    glVertex2f(r/2,-r*1.73/6);
    glVertex2f(0,r*1.73/3);
    glEnd();
}

float Trojkat::zwrocRozmiar()
{
    return r;
}

bool Trojkat::czyKolizja(Figura *druga)
{
    if(druga->zwrocTyp() == TROJKAT)
    {
        return (odleglosc(druga) < (zwrocodlegloscDoKolizji() + druga->zwrocodlegloscDoKolizji()));  //0.5 wysokosci (srednia między 2/3 i 1/3) // 0.9- korekta
    }
    return false;
}

void Trojkat::zmienRozmiar(float dr)
{
    r+=dr;
}

float Trojkat::zwrocPole()
{
    return r*r*1.73/4;
}

void Trojkat::zmienPole(float dp)
{
    float pole = zwrocPole() + dp; // tyle wynosi nowe pole
    zmienRozmiar(sqrt(pole*4/1.73) - r); // obliczenie dlugosci boku na podstawie pola
}

int Trojkat::zwrocTyp()
{
    return TROJKAT;
}

double Trojkat::zwrocodlegloscDoKolizji()
{
    return r*0.433;
}


