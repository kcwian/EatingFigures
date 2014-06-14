#include "odcinek.h"
#include <cmath>
#include <qmath.h>
#include <QTextStream>
#include <QPoint>


Odcinek::Odcinek(GLfloat Ax_, GLfloat Ay_, GLfloat Bx_, GLfloat By_)
{
    Ax = Ax_;
    Ay = Ay_;
    Bx = Bx_;
    By = By_;

    if(Bx-Ax != 0)
        alpha = (qAtan((By-Ay)/(Bx-Ax)));
    else
        alpha = PI*0.5; //

}

void Odcinek::rysuj()
{
    glLoadIdentity();
    glLineWidth(3);
    glColor4f(1,1,1,1);
    glBegin(GL_LINES);
    glVertex2f(Ax,Ay);
    glVertex2f(Bx,By);
    glEnd();
}

void Odcinek::czyKolizja(Figura* figura)
{
    QTextStream out2(stdout);
    GLdouble xF = figura->zwrocPolozenieX();
    GLdouble yF = figura->zwrocPolozenieY();
    GLdouble rF = figura->zwrocodlegloscDoKolizji(); // zmienione z  zwrocRozmiar->*0.5
    GLdouble xPkt;
    GLdouble yPkt;

    //Sprawdzanie, czy moze dojsc do kolizji
    GLfloat p = qMin(Ax,Bx), r = qMax(Ax,Bx), s = qMin(Ay,By), t = qMax(Ay,By);
    if(((xF + rF < p || xF - rF > r || yF+rF < s || yF-rF > t )))
    {
        return;
    }


    GLdouble a = qTan(alpha);
    GLdouble b = By - a*Bx;
    bool kolizja = 0;

    if(alpha != PI*0.5 && alpha != -PI*0.5)
    {

        // Rownanie prostej prostopadłej

        if(a != 0)
        {
            GLdouble a2 = -1/a;
            GLdouble b2 = figura->zwrocPolozenieY() - a2*figura->zwrocPolozenieX();

            // pkt przecięcia prostych

            xPkt = (b-b2)/(a2-a);
            yPkt = a2*xPkt + b2;
        }
        else // jeśli a == 0
        {
            xPkt = figura->zwrocPolozenieX();
            yPkt = b;
        }

    }
    else
    {
        xPkt = Bx;
        yPkt = yF;

    }


    if(figura->odleglosc(xPkt,yPkt) <= figura->zwrocodlegloscDoKolizji())
    {
        kolizja = 1;
    }




            if(kolizja == 1)
    {


        // obliczenie kata figury - beta;
        GLfloat Vx = figura->zwrocPredkoscX();
        GLfloat Vy = figura->zwrocPredkoscY();


        GLfloat modol = qSqrt(Vx*Vx + Vy*Vy);
        GLfloat cosV = Vx/modol;
        GLfloat sinV = Vy/modol;
        GLfloat beta;

        if (qAbs(Vx) == 0)
        {

            if(Vy > 0) // w gore
                beta = PI*0.5;
            else       // w dol
                beta = 1.5*PI;
        }
        else if(Vy == 0 )
        {
            if(Vx > 0) // w prawou
                beta = 0;
            else
                beta = -PI; // w lewo
        }
        else if ( cosV > 0 &&  sinV >0 ) // I ćwiartka
            beta = qAbs(qAtan(Vy/Vx));
        else if(sinV > 0 && cosV < 0) // II ćwiartka
            beta = qAbs(qAtan(Vx/Vy))+PI*0.5;
        else if(sinV <0 && cosV < 0) // III ćwiartka
            beta = qAbs(qAtan(Vy/Vx))+PI;
        else if(sinV <0 && cosV > 0) // IV ćwiartka
            beta = qAbs(qAtan(Vx/Vy))+1.5*PI;

        GLfloat gamma = 2*(alpha-beta); // nowy kąt prędkości
        gamma += beta;
        figura->ustawPredkoscX(modol*qCos(gamma));
        figura->ustawPredkoscY(modol*qSin(gamma));
        QTextStream out(stdout);

    }
}

QDataStream & operator <<(QDataStream &stream, Odcinek* odcinek)
{
    stream << odcinek->Ax;
    stream << odcinek->Ay;
    stream << odcinek->Bx;
    stream << odcinek->By;
    stream << odcinek->alpha;
    return stream;
}

QDataStream & operator >>(QDataStream &stream, Odcinek *odcinek)
{
    stream >> odcinek->Ax;
    stream >> odcinek->Ay;
    stream >> odcinek->Bx;
    stream >> odcinek->By;
    stream >> odcinek->alpha;
    return stream;
}

QDataStream & operator <<(QDataStream &stream, QList <Odcinek*> &listaOdcinkow)
{
    int rozmiarListy = listaOdcinkow.size();
    stream << rozmiarListy; // Pierwszy element to dlugosc listy
    for(int i=0; i<rozmiarListy;i++)
    {
        stream << listaOdcinkow.at(i); // Korzysta z wcześniej przeciążonego operatora dla klasy Figura
    }
    return stream;
}

QDataStream & operator >>(QDataStream &stream, QList <Odcinek*> &listaOdcinkow)
{
    int rozmiarListy;
    stream >> rozmiarListy;

    for(int i=0; i<rozmiarListy;i++)
    {
       Odcinek *odcinek = new Odcinek(1,2,3,4);
       stream >> odcinek;
       listaOdcinkow.append(odcinek);
    }
    return stream;
}
