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
    #ifdef DEBUG
    printf("\x1b[34m//Ziffernreihe: zahl: %i\x1b[0m", reihe);
    #endif
    for (int i=0; i<10; i++)
    {
        if (komplette_ziffernreihe[i] == reihe)
        {
                #ifdef DEBUG
                printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[32mreturn 1 \x1b[0m\n");
                #endif
                return 1;
        }
    }
    #ifdef DEBUG
    printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[31mreturn 0 \x1b[0m\n");
    #endif
    return 0;
}

int main()
{
    FILE * in_ziffernreihe;
    in_ziffernreihe = fopen("ziffernreihe.txt", "r");

    int ziffernreihe[50];

    for (int i=0; i<50; i++)
    {
        fscanf(in_ziffernreihe, " %i,", &ziffernreihe[i]);
    }

    int stelle_max = 0;
    int max = 0;

    for(int i=0; i<50; i++)
    {
        #ifdef DEBUG
        printf("\x1b[35m i = %i \x1b[30m\n", i);
        #endif
        if (komplette_ziffernreihe_pruefung(ziffernreihe[i]) == 1)
        {
            int x = 0;
            for(int j=1; x<1; j++)
            {
                #ifdef DEBUG
                printf("\x1b[35m j = %i \x1b[30m\n", j);
                #endif
                if (komplette_ziffernreihe_pruefung(ziffernreihe[i+j]) == 0)
                {
                    if(j>max)
                    {
                        max = j;
                        stelle_max = i;
                    }
                    i = i + j;
                    x=1;
                }
            }
        }
    }

    if (max < 2)
            printf("In der Ziffernreihe existiert keine längste Reihe nicht aufeinanderfolgender Ziffern! \n");
    else
    {
        printf("Die längste Reihe, nicht aufeinanderfolgender Ziffern ist: %i Ziffern lang. \n", max);
        printf("Die Ziffern lauten: ");

        for(int i=stelle_max; i < stelle_max+max; i++)
        {
            printf("%i, ", ziffernreihe[i]);
        }
        printf("\n");
    }
    fclose(in_ziffernreihe);
    return 0;
}
