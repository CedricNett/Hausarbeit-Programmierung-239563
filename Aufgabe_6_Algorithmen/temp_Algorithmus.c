//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 6 "Suche nach längster Reihe nicht aufeinanderfolgender Ziffern"

#include <stdio.h>
#include <stdlib.h>

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
        }

	int a;

        int ziffernreihe[50];

       for (int i=0; i<50; i++)
        {
                fscanf(zr, " %i,", &ziffernreihe[i]);

                printf(" i = %i -> j = %i \n", i, ziffernreihe[i]);
	}

	printf("\n\n");

		for (int i=0,j=1; i<50,j<50; i++,j++)
		{
			a = ziffernreihe[j] - ziffernreihe[i];

                	printf("%i -> a = %i \n", j, a);

                	if(a == 1)
                	{
                        	printf("return 1 \n\n");
                	}

                	else
                	{
                        	printf("return 0 \n\n");
                	}
		}	
        

    int stelle_max = 0;
    int max = 0;

	fclose(zr);
    return 0;
}
