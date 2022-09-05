//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 6 "Suche nach längster Reihe nicht aufeinanderfolgender Ziffern"

#include <stdio.h>
#include <stdlib.h>

int komplette_ziffernreihe[]={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int komplette_ziffernreihe_pruefung(int reihe)
{

    printf("Ziffernreihe: zahl: %i", reihe);

    for (int i=0; i<10; i++)
    {
        if (komplette_ziffernreihe[i] == reihe)
        {
                printf("DEBUG-PRIMZAHL-PRÜFUNG: return 1 \n");

                return 1;
        }
    }

    printf("DEBUG-PRIMZAHL-PRÜFUNG: return 0 \n");

    return 0;
}

int main()
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

                fclose(zr);
        }

        int ziffernreihe[50];

        for (int i=0; i<50; i++)
        {
                fscanf(zr, " %i,", &ziffernreihe[i]);
                printf(" i = %i \n", i);
        }

    int stelle_max = 0;
    int max = 0;

    return 0;
}
