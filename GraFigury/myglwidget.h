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
    enum {KOLO, KWADRAT, TROJKAT}; //!< Służy do określenia typu każdej figury.
    /*!
     * \brief Konstruktor
     */
    explicit MyGLWidget(QWidget *parent = 0);
    virtual ~MyGLWidget();
    /*!
     * \brief Umożliwia przesłanie listy figur poprzez referencję.
     */
    void przeslijFigury(QList <Figura*> &);

    /*!
     * \brief Umożliwia przesłanie listy odcników, oraz ramki.
     */
    void przeslijInfo(QList <Odcinek*> &,int ramkaPrzyblizania, int);

    /*!
     * \brief Zmienia wartość parametru wywoływanego w funkci glOrtho.
     */
    void zmienOrtho(int);

protected:
    /*!
     * \brief Inicjalizuje OpenGL.
     */
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    int wartoscOrtho; //!< Wartość parametru wywoływanego w funkci glOrtho.
    int ramkaPrzyblizania; //!< Określa zakres pola, na którym toczy się gra.
    GLfloat tlo[4]; //!< Określa kolor tła.
    QList <Figura*> listaFigur; //!< Lista wkaźników klasy Figura. Zawiera wszystkie rysowane figury.
    QList <Odcinek*> listaOdcinkow; //! Zawiera wszystkie odcinki, od których odbijają się figury.
    Figura *sterowana; //!< Zmienna pomocnicza. Wskazuje na figurę, poruszaną przez użytkownika.
    int nrKlienta; //!< Przechowuje numer klienta na liście serwera.


signals:

public slots:


};

#endif // MYGLWIDGET_H
