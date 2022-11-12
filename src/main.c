#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule Cellule; // Déclaration de la structure Cellule

struct Cellule
{
    int val;
    Cellule *suiv;
    Cellule *prec;
}; // Définition de la structure Cellule

typedef Cellule *Liste; // Définition de la structure de la liste

int main(void)
{
    printf("Hello world !\n");
    return 0;
}
