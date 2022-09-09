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

    int ziffernreihe[50];

    for (int i=0; i<50; i++)
    {
        fscanf(zr, " %i,", &ziffernreihe[i]);

        printf(" i = %i -> j = %i \n", i, ziffernreihe[i]);
    }

    int stelle_max = 0;
    int max = 0;
    int i = 0;
    int j = 0;

    for (i=0; i<50; i++)
    {
       // a = ziffernreihe[j] - ziffernreihe[i];
	
	j = i + 1;

//	for (int j=1; x<1; j++)
	while(i == j)
	{
	    a = ziffernreihe[j] - ziffernreihe[i];

	    printf("\n j -> %i  -  i -> %i  =  %i \n", ziffernreihe[j], ziffernreihe[i], a);

            if(a == 1)
            {
                    max = j;

                    stelle_max = i;
            }

            i = i + j;

      //    x = 1;

            printf(" Hier sind aufeinanderfolgende Zahlen \n");
        }
    

       //else
       // {
       //     printf(" Hier sind keine aufeinanderfolgende Zahlen \n");
       // }

    }
    

    if (max < 2)
    {
	    printf("\n In der Zahlenreihe gibt es keine nicht aufeinanderfolgenden Ziffern! \n");
    }

    else
    {
    	printf("\n Die längste Reihe von nicht aufeinanderfolgenden Ziffern ist %i Ziffern lang.\n", max);
    	printf("\n Die Ziffern lauten: ");

    	for(int i=stelle_max; i < stelle_max+max; i++)
    	{
	    printf("%i, ", ziffernreihe[i]);
        }
        printf("\n");
    }

    fclose(zr);
    return 0;
}
