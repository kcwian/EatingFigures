#include "poziomy.h"
#include <QGLWidget>
#include <qmath.h>
Poziomy::Poziomy()
{
}

QList <Figura*> Poziomy::inicjalizuj(int i,int &ramkaPrzyblizania, QList <Odcinek*> &listaOdcinkow) // tworzy figury itd.
{

    QList <Figura*> list;
    switch(i)
    {
    case 0:
    {
        ramkaPrzyblizania = 52;
        list.append(new Kwadrat(10,20,10)); // pierwsza to sterowana
        for (int j=-ramkaPrzyblizania+5; j<ramkaPrzyblizania-5; j+=5)
        {
//            for(int i=-aktualnaramkaPrzyblizania+5,k=1; i< aktualnaramkaPrzyblizania-5; i+=10,k++)
//            {
             list.append(new Kwadrat(i,j,3));
//                if(i%5==0)
//                {
//                    list.at(k)->ustawSpecjalnym(KWADRAT_TROJKAT);
//                }
//            }
        }

        // dodawanie odcinkow
        listaOdcinkow.append(new Odcinek(-50,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,50));
        listaOdcinkow.append(new Odcinek(-50,50,50,50));
        listaOdcinkow.append(new Odcinek(-50,50,-50,-50));

        break;
    }
    case 1:
{
        ramkaPrzyblizania = 80;
        list.append(new Trojkat(0,0,10)); // pierwsza to sterowana

        float r = 80; // promien
        int n = 3;

        float kat = 2*3.1415/n;
        for (int i=0, j=0; i<n; i++)
        {
            j = i+1;
            listaOdcinkow.append(new Odcinek(r*qCos(i*kat),r*qSin(i*kat),r*qCos(j*kat),r*qSin(j*kat)));

        }
        for (int j=-ramkaPrzyblizania+5; j<ramkaPrzyblizania-5; j+=5)
        {
        }
}
        break;

    case 2:
    {
        ramkaPrzyblizania = 80;
        list.append(new Kolo(0,0,10)); // pierwsza to sterowana

        float r = 80; // promien
        int n = 4;

        float kat = 2*3.1415/n;
        for (int i=0, j=0; i<n; i++)
        {
            j = i+1;
            listaOdcinkow.append(new Odcinek(r*qCos(i*kat),r*qSin(i*kat),r*qCos(j*kat),r*qSin(j*kat)));

        }
        for (int j=-ramkaPrzyblizania+5; j<ramkaPrzyblizania-5; j+=5)
        {
        }
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    }
    list.at(0)->ustawPredkoscX(0); // sterowana
    list.at(0)->ustawPredkoscY(0); //
    list.at(0)->ustawOmega(0);     //
    return list;
}

void Poziomy::rysuj(int i) // rysuje scene, bez figur -- mozliwe, że niepotrzebne, bo scena jest w odcinkach
{
    glLoadIdentity();
    glColor3f(1,1,1);
    glLineWidth(2);
    switch(i)
    {
    case 0:
    {

        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    }
}
