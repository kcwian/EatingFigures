#ifndef POZIOMY_H
#define POZIOMY_H
#include <figura.h>
#include <kwadrat.h>
#include <kolo.h>
#include <trojkat.h>
#include <QList>
#include <odcinek.h>

class Poziomy
{
public:
    Poziomy();
    enum {KOLO, KWADRAT, TROJKAT, KOLO_KWADRAT, KOLO_TROJKAT, KWADRAT_TROJKAT, KWADRAT_KOLO, TROJKAT_KOLO, TROJKAT_KWADRAT};
    void inicjalizuj(int,int&,QList <Figura*> &, QList <Odcinek*> &, int);
    void rysuj(int);

};

#endif // POZIOMY_H
