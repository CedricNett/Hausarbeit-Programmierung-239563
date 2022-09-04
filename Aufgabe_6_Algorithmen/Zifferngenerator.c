//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 6 "Suche nach längster Reihe nicht aufeinanderfolgender Ziffern"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MAX 9
#define NUMS_TO_GENERATE 50

int main() {

        int zufallsziffern[NUMS_TO_GENERATE];

        FILE * outstream;
        outstream = fopen("ziffernreihe.txt", "w");


        srand(time(NULL));
        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                zufallsziffern[i] = rand() % MAX;
        }

        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                fprintf(outstream, "%d, ", zufallsziffern[i]);
        }

        fclose(outstream);

        return 0;
}
