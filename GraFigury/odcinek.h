#ifndef ODCINEK_H
#define ODCINEK_H
#include <QGLWidget>
#include "figura.h"
#include <QDataStream>
#define PI 3.14159265

class Odcinek
{
    friend QDataStream & operator <<(QDataStream &stream, Odcinek* odcinek);
    friend QDataStream & operator >>(QDataStream &stream, Odcinek *odcinek);
    friend QDataStream & operator <<(QDataStream &stream, QList <Odcinek*> &listaOdcinkow);
    friend QDataStream & operator >>(QDataStream &stream, QList <Odcinek*> &listaOdcinkow);
public:
    Odcinek();
    Odcinek(GLfloat,GLfloat,GLfloat,GLfloat);
    void rysuj();
    void czyKolizja(Figura* ); // od razu odbija figure, jesli kolizja

private:
    GLdouble Ax, Ay, Bx, By;
    GLdouble alpha; // kat nachylenia
};

#endif // ODCINEK_H
