#include "odcinek.h"
#include <cmath>
#include <qmath.h>
#include <QTextStream>
#include <QPoint>


Odcinek::Odcinek()
{
}

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
    GLdouble rF = figura->zwrocRozmiar()*0.5;
    GLdouble xPkt;
    GLdouble yPkt;

    //Sprawdzanie, czy moze dojsc do kolizji
    GLfloat p = qMin(Ax,Bx), r = qMax(Ax,Bx), s = qMin(Ay,By), t = qMax(Ay,By);
    if(((alpha != 0) && (alpha != PI*0.5) && (xF + rF < p || xF - rF > r || yF+rF < s || yF-rF > t )))
    {

        return;
    }
    if(alpha == 0)
    {
        if (xF+rF <= p || xF-rF >= r)
            return;
    }
    else if(alpha == PI*0.5)
    {
        // out2 << xF << " yF: " << yF;
        if (yF+rF < s || yF-rF > t)
            return;
    }
    //rownanie prostej y = ax + b;

    GLdouble a = qTan(alpha);
    GLdouble b = By - a*Bx;
    bool kolizja = 0;


    //        QPoint A,B; // mogą mieć kolizje

    //        GLfloat roz = figura->zwrocRozmiar()*0.5;
    //        static float k = 1; // ograniczanie ilosci odbic
    //        {
    //        A.setX(figura->zwrocPolozenieX()+ roz* qSin(-alpha));
    //        A.setY(figura->zwrocPolozenieY()+roz* qCos(-alpha));
    //        B.setX(figura->zwrocPolozenieX()+ roz* qSin(-alpha+PI));
    //        B.setY(figura->zwrocPolozenieY()+roz* qCos(-alpha+PI));
    //        if(!(A.x() > Ax && A.x() < Bx ))
    //            break;


    //        if(((qAbs(A.y() - a*A.x()-b) <k) ) || ((qAbs(B.y() - a*B.x()-b)) <k))
    //        {
    //            k=0; // następnego nie będzie
    //             kolizja =1;
    //             out2 << "a: " << a << " b " << b << endl;
    //        }
    //        else
    //        {
    //            k=1; // wraca do poprzedniej wartosci
    //        }

    //}

    //    }

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
        //        out2 << a2 << endl;
        //        out2 << "x: " << xPkt << " y: " << yPkt << endl;
        //        out2 << figura->odleglosc(xPkt,yPkt) << endl;


        //            if(figura->odleglosc(xPkt,yPkt) < figura->zwrocRozmiar()*0.5)
        //            {
        //                kolizja = 1;
        //            }
    }
    else
    {
        xPkt = Bx;
        yPkt = yF;
        //            if(figura->odleglosc(Bx,figura->zwrocPolozenieY()) < figura->zwrocRozmiar()*0.5)
        //                kolizja = 1;
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

        //  GLfloat beta = qAtan(Vy/Vx) *180  / PI;
        GLfloat gamma = 2*(alpha-beta); // nowy kąt prędkości
        gamma += beta;
        // gamma = -90 * PI/180;
        figura->ustawPredkoscX(modol*qCos(gamma));
        figura->ustawPredkoscY(modol*qSin(gamma));
        QTextStream out(stdout);

//        out << "nachylenie prostej: " << alpha*180/PI << " kat predkosci:  " << beta*180/PI << " gamma:  " << gamma*180/PI << endl;
//        out << "Vx:  " << Vx << "Vy: " << Vy << endl;

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
       Odcinek *odcinek = new Odcinek;
       stream >> odcinek;
       listaOdcinkow.append(odcinek);
    }
    return stream;
}

