#include <QGLWidget>
#include <cmath>
#include "kwadrat.h"


using namespace std;

Kwadrat::Kwadrat()
{
    r = 0;
}

Kwadrat::Kwadrat(float x_, float y_, float a_): Figura(x_,y_)
{
    r = a_;
    typ = KWADRAT;

}

Kwadrat::~Kwadrat()
{

}

void Kwadrat::rysuj()
{

    glLoadIdentity();
    glTranslatef(x,y,0);
    glRotatef(alpha,0,0,1);
    glBegin(GL_POLYGON);
    glColor4f(kolor[0],kolor[1],kolor[2],kolor[3]);
    glVertex2f(-r/2,-r/2);
    glVertex2f(r/2,-r/2);
    glVertex2f(r/2,r/2);
    glVertex2f(-r/2,r/2);
    glEnd();



}

float Kwadrat::zwrocRozmiar()
{
    return r;
}


bool Kwadrat::czyKolizja(Figura *druga)
{
    if(druga->zwrocTyp() == KWADRAT)
    {
        return(odleglosc(druga) < (zwrocodlegloscDoKolizji() + druga->zwrocodlegloscDoKolizji()));
    }
    return false;

}

void Kwadrat::zmienRozmiar(float dr)
{
    r += dr;
}

float Kwadrat::zwrocPole()
{
    return r*r;
}

void Kwadrat::zmienPole(float dp)
{
    float pole = zwrocPole() + dp;

    zmienRozmiar(sqrt(pole) - r);
}

int Kwadrat::zwrocTyp()
{
    return KWADRAT;
}

double Kwadrat::zwrocodlegloscDoKolizji()
{
    return r*0.6036; // (srednia przekątnej i boku) *0.5
}


