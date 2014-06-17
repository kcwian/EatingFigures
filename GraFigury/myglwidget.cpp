#include "myglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTextStream>

#include <QWheelEvent>
#include <cmath>

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    tlo[0] = 0.3;
    tlo[1]  = 0.2;
    tlo[2] = 0.4;
    tlo[3] = 1;
    sterowana = 0 ;
    wartoscOrtho = 52;
}

MyGLWidget::~MyGLWidget()
{
    for (int i=0; i<listaFigur.length(); i++)
    {
        delete listaFigur.at(i);
    }
}


void MyGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);     //!< Ustawia glębię.

}

void MyGLWidget::resizeGL(int w, int h)
{
    int s = qMin(w,h);
    glViewport((w-s)/2, (h-s)/2, s, s);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(wartoscOrtho <= ramkaPrzyblizania && sterowana != 0)
    {
        float x = sterowana->zwrocPolozenieX(), y = sterowana->zwrocPolozenieY();
        glOrtho(-wartoscOrtho+x, wartoscOrtho+x, -wartoscOrtho+y, wartoscOrtho+y, -1 ,1 );
    }
    else
    {
        glOrtho(-wartoscOrtho, wartoscOrtho, -wartoscOrtho, wartoscOrtho, -1 ,1 );

    }
    glMatrixMode(GL_MODELVIEW);



}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(tlo[0],tlo[1],tlo[2],tlo[3]);

    if( listaFigur.size() > 0 || listaOdcinkow.size() >0)
    {
        for (int i=0; i<listaFigur.size(); i++)
        {
            listaFigur.at(i)->rysuj();

        }

        for (int i=0; i<listaOdcinkow.size();i++)
        {
            listaOdcinkow.at(i)->rysuj();
        }


    }

    else
    {
        glLoadIdentity();
        glBegin(GL_POLYGON);
        glVertex2d(0,0);

        glEnd();

    }


}



void MyGLWidget::przeslijFigury(QList <Figura*> &list1)
{
    listaFigur = list1;
    sterowana = list1.at(nrKlienta);
    if(wartoscOrtho <= ramkaPrzyblizania && sterowana != 0)
    {
        resizeGL(width(),height());
    }
}

void MyGLWidget::przeslijInfo(QList <Odcinek*> &list1,int ramkaPrzyblizania_, int nrKlienta_)
{
    listaOdcinkow = list1;
    ramkaPrzyblizania = ramkaPrzyblizania_;
    wartoscOrtho = ramkaPrzyblizania+2;
    nrKlienta = nrKlienta_;
    resize(width(),height());
}

void MyGLWidget::zmienOrtho(int value)
{
    wartoscOrtho += value;
    resizeGL(width(),height());
}
