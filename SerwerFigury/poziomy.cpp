#include <QGLWidget>
#include <qmath.h>
#include "poziomy.h"
#include <QTextStream>
Poziomy::Poziomy()
{
}

void Poziomy::inicjalizuj(int i,int &ramkaPrzyblizania,QList <Figura*> &list, QList <Odcinek*> &listaOdcinkow,int liczbaKlientow) // tworzy figury itd.
{

    ramkaPrzyblizania = 52;
    switch(i)
    {
    case 0:
    {

        ramkaPrzyblizania = 52;
        int d = 90/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
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
        int d = 90/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {
            Figura *ster = new Kwadrat(-50+i*d,0,5);
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
        Figura *nowa2;
        int d = 90/(liczbaKlientow+1);
        for(int i=1;i<liczbaKlientow+1;i++)
        {
            nowa2 = new Kolo(-50+i*d,-25,3.5);
            nowa2->ustawPredkoscX(0);
            nowa2->ustawPredkoscY(0);
            nowa2->ustawOmega(0);
            list.append(nowa2); // pierwsza to sterowana
        }
        for(int i =-40; i<50; i+=10)
        {
            list.append(new Kolo(40,i,2));
            list.append(new Kolo(20,i,2));
            if(i<-5 && i > -45)
            {
                list.append(new Kolo(-40,i,2));
                list.append(new Kolo(-30,i,2));
                list.append(new Kolo(-20,i,2));
                list.append(new Kolo(0,i,2));
            }
        }

        listaOdcinkow.append(new Odcinek(-50,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,50));
        listaOdcinkow.append(new Odcinek(0,50,50,50));
        listaOdcinkow.append(new Odcinek(0,0,0,50));
        listaOdcinkow.append(new Odcinek(-50,0,0,0));
        listaOdcinkow.append(new Odcinek(-50,0,-50,-50));
        break;

    }
    case 3:
    {

        ramkaPrzyblizania = 62;
        Figura *nowa2;
        int d = 100/(liczbaKlientow+1);
        for(int i=1;i<liczbaKlientow+1;i++)
        {
            nowa2 = new Kolo(-50+i*d,-25,3.5);
            nowa2->ustawPredkoscX(0);
            nowa2->ustawPredkoscY(0);
            nowa2->ustawOmega(0);
            list.append(nowa2); // pierwsza to sterowana
        }

        for(int i=-45; i<25; i+=10)
        {
            list.append(new Kolo(-30,i,2));
            list.append(new Kolo(-15,i,2));
            list.append(new Kolo(15,i,2));
            list.append(new Kolo(30,i,2));
            list.append(new Kolo(-40,i,2));
            list.append(new Kolo(40,i,2));

        }

        for(int i=-45; i<55; i+=10)
        {
            list.append(new Kolo(0,i,2));

        }

        listaOdcinkow.append(new Odcinek(-50,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,20));
        listaOdcinkow.append(new Odcinek(0,50,50,20));
        listaOdcinkow.append(new Odcinek(-50,20,0,50));
        listaOdcinkow.append(new Odcinek(-50,-50,-50,20));
        listaOdcinkow.append(new Odcinek(-50,20,-15,20));
        listaOdcinkow.append(new Odcinek(15,20,50,20));
        break;
    }
    case 4:
    {
        ramkaPrzyblizania = 52;
        int d = 100/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {

            Figura *ster = new Trojkat(-50+i*d,-25,6);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        for (int i=-45;i<45;i+=10)
        {
            list.append(new Trojkat(i,30,4));
            list.append(new Trojkat(i,-30,4));
            list.append(new Trojkat(i,-40,4));
            list.append(new Trojkat(i,40,4));
        }


        listaOdcinkow.append(new Odcinek(-50,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,50));
        listaOdcinkow.append(new Odcinek(-50,50,50,50));
        listaOdcinkow.append(new Odcinek(-50,50,-50,-50));
        listaOdcinkow.append(new Odcinek(-15,-15,15,-15));
        listaOdcinkow.append(new Odcinek(15,-15,15,15));
        listaOdcinkow.append(new Odcinek(-15,15,15,15));
        listaOdcinkow.append(new Odcinek(-15,15,-15,-15));
        break;
    }
    case 5:
    {


        int d = 100/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {

            Figura *ster = new Kolo(-50+i*d,0,3.5);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        for (int i=-45;i<45;i+=7)
        {
            list.append(new Kolo(-40,i,2));
            list.append(new Kolo(-30,i,2));
            list.append(new Kolo(-20,i,2));
            list.append(new Kolo(20,i,2));
            list.append(new Kolo(30,i,2));
            list.append(new Kolo(40,i,2));

        }

        listaOdcinkow.append(new Odcinek(-10,-10,10,-10));
        listaOdcinkow.append(new Odcinek(-10,10,10,10));

        listaOdcinkow.append(new Odcinek(-10,-10,-10,-50));
        listaOdcinkow.append(new Odcinek(-10,10,-10,50));
        listaOdcinkow.append(new Odcinek(10,-10,10,-50));
        listaOdcinkow.append(new Odcinek(10,10,10,50));

        listaOdcinkow.append(new Odcinek(-50,-50,-10,-50));
        listaOdcinkow.append(new Odcinek(-50,-50,-50,50));
        listaOdcinkow.append(new Odcinek(-50,50,-10,50));

        listaOdcinkow.append(new Odcinek(10,-50,50,-50));
        listaOdcinkow.append(new Odcinek(50,-50,50,50));
        listaOdcinkow.append(new Odcinek(10,50,50,50));


        break;
    }
    case 6:
    {

        int d = 100/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {

            Figura *ster = new Kwadrat(-50+i*d,0,3.5);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        // Figury
        for (int i=-45;i<45;i+=7)
        {
            list.append(new Kwadrat(-10,i,2));
            list.append(new Kwadrat(0,i,2));
            list.append(new Kwadrat(10,i,2));
            list.append(new Kwadrat(i,10,2));
            list.append(new Kwadrat(i,0,2));
            list.append(new Kwadrat(i,-10,2));

        }


        listaOdcinkow.append(new Odcinek(-50,16,-50,-16));
        listaOdcinkow.append(new Odcinek(-50,-16,-16,-16));
        listaOdcinkow.append(new Odcinek(-16,-16,-16,-50));
        listaOdcinkow.append(new Odcinek(-16,-50,16,-50));
        listaOdcinkow.append(new Odcinek(16,-16,16,-50));
        listaOdcinkow.append(new Odcinek(16,-16,50,-16));
        listaOdcinkow.append(new Odcinek(50,-16,50,16));

        listaOdcinkow.append(new Odcinek(-50,16,-16,16));
        listaOdcinkow.append(new Odcinek(-16,16,-16,50));
        listaOdcinkow.append(new Odcinek(-16,50,16,50));
        listaOdcinkow.append(new Odcinek(16,50,16,16));
        listaOdcinkow.append(new Odcinek(16,16,50,16));
        break;
    }
    case 7:
    {

        int d = 100/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {

            Figura *ster = new Kolo(-50+i*d,-15,2);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        // Figury
        for (int i=-45;i<45;i+=7)
        {
            list.append(new Kolo(i,-15,1));
            list.append(new Kolo(i,-25,1));
            if( i > -20 && i < 35)
                list.append(new Kolo(i,0,1));

        }


        // Karoseria
        listaOdcinkow.append(new Odcinek(-50,-30,-50,-10));
        listaOdcinkow.append(new Odcinek(-50,-30,50,-30));
        listaOdcinkow.append(new Odcinek(-50,-10,-30,-10));
        listaOdcinkow.append(new Odcinek(-30,-10,-10,20));
        listaOdcinkow.append(new Odcinek(-10,20,30,20));
        listaOdcinkow.append(new Odcinek(30,20,40,-10));
        listaOdcinkow.append(new Odcinek(40,-10,50,-10));
        listaOdcinkow.append(new Odcinek(50,-10,50,-30));

        //Kola
        float r = 5; // promien
        int n = 6;
        float kat = 2*3.1415/n;
        for (int i=0, j=0; i<n; i++)
        {
            j = i+1;
            listaOdcinkow.append(new Odcinek(r*qCos(i*kat)-35,r*qSin(i*kat)-35,r*qCos(j*kat)-35,r*qSin(j*kat)-35));
            listaOdcinkow.append(new Odcinek(r*qCos(i*kat)+35,r*qSin(i*kat)-35,r*qCos(j*kat)+35,r*qSin(j*kat)-35));
        }



        break;
    }
    case 8:
    {
        int d = 100/(liczbaKlientow+1);
        for (int i = 1; i<liczbaKlientow+1; i++)
        {

            Figura *ster = new Kolo(30,-50+i*d,2);
            ster->ustawPredkoscX(0);
            ster->ustawPredkoscY(0);
            ster->ustawOmega(0);
            list.append(ster);
        }

        // Figury
        for (int i=-40, j =-25;i<40;i+=7, j+=7)
        {
            list.append(new Kolo(i,40,2));
            list.append(new Kolo(j,25,2));
            if(i>-10 && i < 45)
                list.append(new Kolo(i,0,2));
            if (i> 10 && i < 45)
                list.append(new Kolo(i,-30,2));
        }

        listaOdcinkow.append(new Odcinek(-50,50,50,50));
        listaOdcinkow.append(new Odcinek(50,50,50,-50));
        listaOdcinkow.append(new Odcinek(-50,50,-50,30));
        listaOdcinkow.append(new Odcinek(-50,30,-30,30));
        listaOdcinkow.append(new Odcinek(-30,30,-30,10));
        listaOdcinkow.append(new Odcinek(-30,10,-10,10));
        listaOdcinkow.append(new Odcinek(-10,10,-10,-10));
        listaOdcinkow.append(new Odcinek(-10,-10,10,-10));
        listaOdcinkow.append(new Odcinek(10,-10,10,-50));
        listaOdcinkow.append(new Odcinek(10,-50,50,-50));



        break;
    }

    case 9:


        break;
    }



    list.at(0)->ustawPredkoscX(0); // sterowana
    list.at(0)->ustawPredkoscY(0); //
    list.at(0)->ustawOmega(0);     //

}

