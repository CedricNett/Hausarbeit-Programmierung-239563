//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 6 "Suche nach längster Reihe nicht aufeinanderfolgender Ziffern"

#include <stdio.h>
#include <stdlib.h>

#define MAX_ZIFFERN 100

// Daten einlesen
int daten_einlesen(int daten[MAX_ZIFFERN])
{
    FILE * zr;
    zr = fopen("ziffernreihe.txt", "r");

    if(zr == NULL)
    {
        printf("Datei konnte NICHT geöffnet werden.\n");
    }

    else
    {
        printf("Datei konnte geöffnet werden.\n");
    }

    int i = 0;
    int r = 1;

    while(r != EOF && i-1 < MAX_ZIFFERN)
    {
        r = fscanf(zr, " %i,", &daten[i]);
        i++;
    }

    fclose(zr);
    return i-1;
}

//Daten verarbeiten und ausgeben
int main()
{
    int ziffernreihe[MAX_ZIFFERN];

    for(int i =0; i<MAX_ZIFFERN; i++)
    {
        ziffernreihe[i]=0;
    }

    int daten_laenge = daten_einlesen(ziffernreihe);
    int rechnungs_zwischenschritt = 0;
    int position_max = 0;
    int laenge_max = 0;
    int start=0;

    for (int i = 0; i<daten_laenge; i++)
    {
        rechnungs_zwischenschritt = ziffernreihe[i+1] - ziffernreihe[i];

        printf("\n i+1 -> %i  -  i -> %i  =  a -> %i \n", ziffernreihe[i+1], ziffernreihe[i], rechnungs_zwischenschritt);

        if(rechnungs_zwischenschritt == 1) // reihe ist zuende
        {
            int laenge = i-start-1;
            // neue laenge größer als vorherige reihe
            if(laenge > laenge_max)
            {
                position_max = i - laenge;
                laenge_max = laenge;
            }

            start=i; //neuer startpunkt

            printf(" Hier sind aufeinanderfolgende Ziffern \n");
        }

        else
        {
            printf(" Hier sind keine aufeinanderfolgende Ziffern \n");
        }

    }

    if (laenge_max < 2)
    {
        printf("\n In der Ziffernreihe gibt es keine nicht aufeinanderfolgenden Ziffern! \n");
    }

    else
    {
        printf("\n Die längste Reihe von nicht aufeinanderfolgenden Ziffern ist %i Ziffern lang.\n", laenge_max);
        printf("\n Die Ziffern lauten: ");

        for(int i=0; i < laenge_max; i++)
        {
            printf("%i, ", ziffernreihe[i + position_max]);
        }
        printf("\n");
    }

    return 0;
}
