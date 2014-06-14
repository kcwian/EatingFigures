#ifndef POZIOMY_H
#define POZIOMY_H
#include "figura.h"
#include <kwadrat.h>
#include <kolo.h>
#include <trojkat.h>
#include <QList>
#include "odcinek.h"


/*!
 * \brief Klasa umożliwiająca tworzenie nowych poziomów.
 */
class Poziomy
{
public:
    /*!
     * \brief Konstruktor.
     */
    Poziomy();
    enum {KOLO, KWADRAT, TROJKAT}; //!< Typ wyliczeniowy, służący do identyfikacji każdej figury.
    /*!
     * \brief Inicjalizuje poziom, tworząc listę figur, listę odcinków (przekazane przez referencję) oraz ustalając ramkę.
     */
    void inicjalizuj(int nrPoziomu,int& ramkaPrzyblizania,QList <Figura*> &, QList <Odcinek*> &, int liczbaKlientow);

};

#endif // POZIOMY_H
