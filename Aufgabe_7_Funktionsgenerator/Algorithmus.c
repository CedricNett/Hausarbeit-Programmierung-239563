//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          15.09.2022
//      Hausarbeit:     Aufgabe 7 "Rechteckgenerator"

#include <stdio.h>
#include "Algorithmus_static.h"
#include <stdlib.h>
#include <getopt.h>

int main()
{
    int maximalwert;
    int periodendauer;
    int frequenz;

    printf("\nMaximalwert angeben: ");
    scanf("%i",&maximalwert);

    printf("\nFrequenz angeben: ");
    scanf("%i",&frequenz);

    printf("\nPeriodendauer angeben: ");
    scanf("%i",&periodendauer);

    FILE *Rechteckgenerator_file;
    Rechteckgenerator_file = fopen ("Rechteckgenerator_file.txt", "w");

    for(int i = 0; i < periodendauer; i++) {
        Rechteckfunktion(maximalwert, frequenz, i, Rechteckgenerator_file);
    }

    if(Rechteckgenerator_file == NULL)
    {
        printf("\nDatei konnte NICHT erstellt werden.\n");
        exit(0);
    }

    else
    {
        printf("\nDatei konnte erstellt werden. Die Datei nennt sich Rechteckgenerator_file.txt\n");
    }

    fclose(Rechteckgenerator_file);

    return 0;
}
