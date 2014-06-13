#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QPointF>
#include <kolo.h>
#include <kwadrat.h>
#include <trojkat.h>
#include <QList>
#include <QTimer>
#include <poziomy.h>
#include <odcinek.h>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    enum {KOLO, KWADRAT, TROJKAT};
    explicit MyGLWidget(QWidget *parent = 0);
    virtual ~MyGLWidget();
    void przeslijFigury(QList <Figura*> &);
    void przeslijInfo(QList <Odcinek*> &,int ramkaPrzyblizania, int);
    void zmienOrtho(int);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
   // void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void animacjaPrzyblizania();
   // void przeslijDane(QList <Figura*> &,QList <Odcinek*> &);


    int wartoscOrtho;
    int ramkaPrzyblizania;
    GLfloat tlo[4];
    QList <Figura*> listaFigur;
    QList <Odcinek*> listaOdcinkow;
    Figura *sterowana;
    QPointF lastPos;
    int aktualnyPoziom;
    int nrKlienta;


signals:

public slots:


};

#endif // MYGLWIDGET_H
