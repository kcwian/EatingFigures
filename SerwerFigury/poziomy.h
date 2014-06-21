#ifndef POZIOMY_H
#define POZIOMY_H
#include "figura.h"
#include <kwadrat.h>
#include <kolo.h>
#include <trojkat.h>
#include <QList>
#include "odcinek.h"

/*!
 * \brief Klasa, służąca do tworzenia poziomów.
 */
class Poziomy
{
public:
    Poziomy();
    enum {KOLO, KWADRAT, TROJKAT};//!< Typ wyliczeniowy, służący do identyfikacjy każdej figury.

    /*!
     * \brief Inicjalizuje poziom, tworząc listę figur, listę odcinków (przekazanych przez referencję) oraz ustala rozmiar ramki.
     */
    void inicjalizuj(int nrKlienta ,int& ramka ,QList <Figura*> &, QList <Odcinek*> &, int liczbaKlientow);

};

#endif // POZIOMY_H
