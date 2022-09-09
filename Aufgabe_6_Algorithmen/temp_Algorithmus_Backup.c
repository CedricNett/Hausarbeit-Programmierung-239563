//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 6 "Suche nach längster Reihe nicht aufeinanderfolgender Ziffern"

#include <stdio.h>
#include <stdlib.h>

int main()
{

//  Hier wird geschaut ob die Zifferndatei geöffnet wurde
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

// Hier werden die Ziffern der Datei mit Integers versehen um diese später zu nutzen

    int a;
    const int max_ziffern = 50;
    int ziffernreihe[max_ziffern];

 /*   for (int i=0; i<50; i++)
    {
        fscanf(zr, " %i,", &ziffernreihe[i]);

        printf(" i = %i -> j = %i \n", i, ziffernreihe[i]);
    } */

    int i_max = 0;
    int j_max = 0;

    //for ( i, j; i<50, j<50; i++ ,j++)
    for (int i = 0; i<max_ziffern; i++)
    {
	int j = 0;

	j = i + 1;

        fscanf(zr, " %i,", &ziffernreihe[i]);

	fscanf(zr, " %i,", &ziffernreihe[j]);

        a = ziffernreihe[j] - ziffernreihe[i];

        printf("\n j -> %i  -  i -> %i  =  a -> %i \n", ziffernreihe[j], ziffernreihe[i], a);

        if(a == 1)
        {
            j_max = j;

            i_max = i;
    
            printf(" Hier sind aufeinanderfolgende Zahlen \n");
        }

        else
        {
            printf(" Hier sind keine aufeinanderfolgende Zahlen \n");
        }

    }

    if (j_max < 2)
    {
            printf("\n In der Zahlenreihe gibt es keine nicht aufeinanderfolgenden Ziffern! \n");
    }

    else
    {
        printf("\n Die längste Reihe von nicht aufeinanderfolgenden Ziffern ist %i Ziffern lang.\n", j_max);
        printf("\n Die Ziffern lauten: ");

        for(int i=i_max; i < i_max+j_max; i++)
        {
            printf("%i, ", ziffernreihe[i]);
        }
        printf("\n");
    }

    fclose(zr);
    return 0;
}
