#ifndef ODCINEK_H
#define ODCINEK_H
#include <QGLWidget>
#include "figura.h"
#include <QDataStream>
#define PI 3.14159265

/*!
 * \brief Klasa umożliwiająca rysowanie Odcinka AB oraz odbicie obiektów klasy Figura.
 */
class Odcinek
{
    /*!
     * \brief Operator służący do wysyłania obiektu klasy Odcinek na strumień.
     */
    friend QDataStream & operator <<(QDataStream &stream, Odcinek* odcinek);
    /*!
     * \brief Operator służący do wczytywania obiektu klasy Odcinek z strumienia.
     */
    friend QDataStream & operator >>(QDataStream &stream, Odcinek *odcinek);
    /*!
     * \brief Operator służący do wysyłania listy obiektów klasy Odcinek na strumień.
     */
    friend QDataStream & operator <<(QDataStream &stream, QList <Odcinek*> &listaOdcinkow);
    /*!
     * \brief Operator służący do wczytywania listy obiektów klasy Odcinek z strumienia.
     */
    friend QDataStream & operator >>(QDataStream &stream, QList <Odcinek*> &listaOdcinkow);
public:
    /*!
     * \brief Konstruktor parametryczny. Tworzy odcinek AB
     * \param x1 Współrzędna X punktu A.
     * \param y1 Współrzędna Y punktu A.
     * \param x2 Współrzędna X punktu B.
     * \param y2 Współrzędna Y punktu B.
     */
    Odcinek(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2);
    /*!
     * \brief Rysuje odcinek.
     */
    void rysuj();

    /*!
     * \brief Sprawdza, czy nastąpiła kolizja z figurą, jeśli tak, to następuje jej odbicie.
     */
    void czyKolizja(Figura* ); // od razu odbija figure, jesli kolizja

private:
    /*!
     * \brief
     */
    GLdouble Ax; //!< Współrzędna X punktu A.
    GLdouble Ay;//!< Współrzędna Y punktu A.
    GLdouble Bx;//!< Współrzędna X punktu B.
    GLdouble By; //!< Współrzędna Y punktu B.
    GLdouble alpha; //! Kąt naychlenia prostej.
};

#endif // ODCINEK_H
