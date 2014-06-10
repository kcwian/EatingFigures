#include <QGLWidget>
#include <qmath.h>
#include "poziomy.h"
Poziomy::Poziomy()
{
}

void Poziomy::inicjalizuj(int i,int &ramkaPrzyblizania,QList <Figura*> &list, QList <Odcinek*> &listaOdcinkow,int liczbaKlientow) // tworzy figury itd.
{


    switch(i)
    {
    case 0:
    {
        for (int i = 0; i<liczbaKlientow; i++)
        {
            Figura *ster = new Kolo(-30,25+i*5,4);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }
        ramkaPrzyblizania = 52;


        Figura *nowa2;
        for (int j=-45; j<45; j+=20)
        {
            for (int i = -45; i<45;i+=20)
            {

                nowa2 = new Kolo(i,j,3);
                nowa2->ustawPredkoscX(3);
                nowa2->ustawPredkoscY(3);
                list.append(nowa2);
            }

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

        for (int i = 0; i<liczbaKlientow; i++)
        {
            Figura *ster = new Kolo(qrand()%100-50,qrand()%100-50,2);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        Figura *nowa2;
        for (int j=-25; j<45; j+=20)
        {
            for (int i = -45; i<25;i+=20)
            {

                nowa2 = new Trojkat(i,j,3);
                nowa2->ustawPredkoscX(1);
                nowa2->ustawPredkoscY(1);
                list.append(nowa2);
            }

        }

        float r = 80; // promien
        int n = 3;
        float kat = 2*3.1415/n;
        for (int i=0, j=0; i<n; i++)
        {
            j = i+1;
            listaOdcinkow.append(new Odcinek(r*qCos(i*kat),r*qSin(i*kat),r*qCos(j*kat),r*qSin(j*kat)));
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
