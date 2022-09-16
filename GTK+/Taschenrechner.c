//      Autor:          Cedric-Julian Nettler
//      Mail:           cedric-julian.nettler@stud.thga.de
//      Matr. Nr.:      239563
//      Datum:          29.08.2022
//      Hausarbeit:     Aufgabe 11 "Der GTK+ Taschenrechner"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

int zaehlen = 0;
int addieren = 0;
int subtrahieren = 0;
int multiplizieren = 0;
int dividieren = 0;
int ergebnis = 0;
int zahl1;
int zahl2;
int check = 0;

char rechnen[9]={0,0,0,0,0,0,0,0,0,0}; //

GtkWidget *fenster;
GtkWidget *knopf;
GtkWidget *tisch;
GtkWidget *ergenisanzeige;

static void addieren_(GtkWidget *widget, gpointer data)
{
    zaehlen = 0;

    addieren = 1;

    int i = rech(rechnen);

    for (int i = 0; i < 10; i++)
    {
        rechnen[i] = 0;
    }
}

static void subtrahieren_(GtkWidget *widget, gpointer data)
{
    zaehlen = 0;

    subtrahieren = 1;

    int i = rech(rechnen);

    for (int i = 0; i < 10; i++)
    {
        rechnen[i] = 0;
    }
}

static void multiplizieren_(GtkWidget *widget, gpointer data)
{
    zaehlen = 0;

    multiplizieren = 1;

    int i = rech(rechnen);

    for (int i = 0; i < 10; i++)
    {
        rechnen[i] = 0;
    }
}

static void dividieren_(GtkWidget *widget, gpointer data)
{
    zaehlen = 0;

    dividieren = 1;

    int i = rech(rechnen);

    for (int i = 0; i < 10; i++)
    {
        rechnen[i] = 0;
    }
}

static void taste(GtkWidget *button, gpointer *data)
{
    rechnen[zaehlen] = data;

    zaehlen++;

    int ix = rech(rechnen);

    zahl2 = ix;
}

static void gleich(GtkWidget *button, gpointer *data)
{
    int buffer[9];

    if(addieren == 1)
    {
        snprintf(buffer, sizeof(buffer), "%i", zahl1 + zahl2);

        zaehlen = 0;

        addieren = 0;

        for (int i = 0; i < 10; i++)
        {
            rechnen[i] = 0;
        }
    }

    if(subtrahieren == 1)
    {
        snprintf(buffer, sizeof(buffer), "%i", zahl1 - zahl2);

        zaehlen = 0;

        subtrahieren = 0;

        for (int i = 0; i < 10; i++)
        {
            rechnen[i] = 0;
        }
    }

    if(multiplizieren == 1)
    {
        snprintf(buffer, sizeof(buffer), "%i", zahl1 * zahl2);

        zaehlen = 0;

        multiplizieren = 0;

        for (int i = 0; i < 10; i++)
        {
            rechnen[i] = 0;
        }
    }

    if(dividieren == 1)
    {
        snprintf(buffer, sizeof(buffer), "%i", zahl1 / zahl2);

        zaehlen = 0;

        dividieren = 0;

        for (int i = 0; i < 10; i++)
        {
            rechnen[i] = 0;
        }
    }

    gtk_label_set_text(GTK_LABEL(ergenisanzeige), buffer);
}


