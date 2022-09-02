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
#define MAX 1000
#define NUMS_TO_GENERATE 1000

int main() {

        int zufallszahlen[NUMS_TO_GENERATE];

        FILE * outstream;
        outstream = fopen("zahlenreihe.txt", "w");

	
	srand(time(NULL));
        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                zufallszahlen[i] = rand() % MAX;
        }

        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                fprintf(outstream, "%d, ", zufallszahlen[i]);
        }

        fclose(outstream);

        return 0;
}
