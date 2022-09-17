//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          15.09.2022
//      Hausarbeit:     Aufgabe 7 "Rechteckfunktion"

#include <stdio.h>

void Rechteckfunktion(int maximalwert, int frequenz, int i, FILE *Rechteckgenerator_file)
{
    if((i / frequenz) % 2)
    {
    	fprintf(Rechteckgenerator_file, "%d \n", maximalwert);
    }

    else
    {
    	fprintf(Rechteckgenerator_file, "-%d\n", maximalwert);
    }
}
/*
void Rechteckfunktion(int maximalwert, int frequenz, int i, FILE *Rechteckgenerator_file)
{
    while(i < (frequenz/2))
    {
        fprintf(Rechteckgenerator_file, "%d \n", maximalwert);
        i++;
    }

    while(i < frequenz)
    {
        fprintf(Rechteckgenerator_file, "-%d\n", maximalwert);
        i++;
    }
}
*/
