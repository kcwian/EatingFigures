#include <QGLWidget>
#include <qmath.h>
#include "poziomy.h"
#include <QTextStream>
Poziomy::Poziomy()
{
}

void Poziomy::inicjalizuj(int i,int &ramkaPrzyblizania,QList <Figura*> &list, QList <Odcinek*> &listaOdcinkow,int liczbaKlientow) // tworzy figury itd.
{


    switch(i)
    {
    case 0:
    {

        ramkaPrzyblizania = 52;
        int d = 90/liczbaKlientow;
        for (int i = 0; i<liczbaKlientow; i++)
        {

            Figura *ster = new Kolo(-40+i*d,0,4);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

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
        ramkaPrzyblizania = 52;
        int d = 140/liczbaKlientow;
        for (int i = 0; i<liczbaKlientow; i++)
        {
            Figura *ster = new Kwadrat(-25+i*d,0,5);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        Figura *nowa2;
        for (int j= -30; j<=30; j+=10)
        {
            for (int i = -30; i<=30;i+=10)
            {
                nowa2 = new Kwadrat(i,j,3);
//                nowa2->ustawPredkoscX(1);
//                nowa2->ustawPredkoscY(1);
                list.append(nowa2);
            }

        }

        float r = 50; // promien
        int n = 6;
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
        ramkaPrzyblizania = 52;
        int d = 90/liczbaKlientow;
        for(int i=0;i<liczbaKlientow;i++)
        {
        list.append(new Kolo(-25+i*d,-25,5)); // pierwsza to sterowana
        }
        for(int i =-40; i<40; i+=8)
        {
            list.append(new Kolo(25,i,3));
        }

        listaOdcinkow.append(new Odcinek(-50,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,50));
        listaOdcinkow.append(new Odcinek(0,50,50,50));
        listaOdcinkow.append(new Odcinek(0,0,0,50));
        listaOdcinkow.append(new Odcinek(-50,0,0,0));
        listaOdcinkow.append(new Odcinek(-50,0,-50,-50));

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
