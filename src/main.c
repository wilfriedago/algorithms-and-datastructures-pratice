#include <stdio.h>
#include <stdlib.h>

/***********************************************
 *      Fonctions & Procédures utilitaires     *
 ***********************************************/

/**
 * @brief Procédure permettant d'afficher le menu du jeu
 */
void displayMenu()
{
    // rectangle(POS_X - 1, POS_Y - 1, 25, 2);
    // rectangle(POS_X - 1, POS_Y + 2, 25, 5);
    // rectangle(POS_X - 1, POS_Y + 8, 25, 2);

    // gotoxy(POS_X + 10, POS_Y);
    printf("MENU");

    // gotoxy(POS_X + 1, POS_Y + 3);
    printf("1. Créer une liste chaînée d'entier");

    // gotoxy(POS_X + 1, POS_Y + 4);
    printf("2. Ajouter un element en tete de liste");

    // gotoxy(POS_X + 1, POS_Y + 5);
    printf("3. Ajouter un élément en queue de liste");

    // gotoxy(POS_X + 1, POS_Y + 6);
    printf("4. Tier la liste");

    // gotoxy(POS_X + 1, POS_Y + 7);
    printf("5. Supprimer un élément donné de la liste");

    // gotoxy(POS_X + 1, POS_Y + 8);
    printf("6. Supprimer les doublons de la liste");

    // gotoxy(POS_X + 1, POS_Y + 9);
    printf("7. Supprimer le dernier élément de la liste");

    // gotoxy(POS_X + 1, POS_Y + 10);
    printf("8. Fusionner deux listes");

    // gotoxy(POS_X + 1, POS_Y + 11);
    printf("9. Inverser la liste");

    // gotoxy(POS_X + 1, POS_Y + 12);
    printf("10. Vérifier si une liste est un palindrome");

    // gotoxy(POS_X + 1, POS_Y + 13);
    printf("11. Quitter");
}

/**
 * @brief Fonction permettant de lire une caractère saisie à la console
 * @param message Message à afficher dans la console
 * @return char*
 */
int readNumber(char *message)
{
    int choice;
    printf("%s", message);
    scanf("%d", &choice);
    return choice;
}

/***********************************************
 *  x  Fonctions & Procédures utilitaires   x  *
 ***********************************************/

typedef struct Cellule Cellule; // Déclaration de la structure Cellule

struct Cellule
{
    int val;
    Cellule *suiv;
    Cellule *prec;
}; // Définition de la structure Cellule

typedef Cellule *Liste; // Définition de la structure de la liste

/**
 * @brief Fonction permettant de créer une liste chaînée d'une taille donnée
 * @param list Liste passé en paramètre par variable
 * @param size Taille de la liste
 */
void createList(Liste *list, int size)
{
    Cellule *P = malloc(sizeof(Cellule));

    if (P == NULL)
        exit(EXIT_FAILURE);

    P->val = (int)readNumber("Saisissez une valeur : ");
    P->suiv = NULL;
    P->prec = NULL;

    *list = P;

    for (int i = 2; i <= size; i++)
    {
        Cellule *Q = malloc(sizeof(Cellule));

        if (Q == NULL)
            exit(EXIT_FAILURE);

        Q->val = (int)readNumber("Saisissez une valeur : ");
        Q->suiv = NULL;
        Q->prec = P;

        P->suiv = Q;
        P = Q;
    }
}

/**
 * @brief Procédure permettant d'afficher une liste
 */
void printList(Liste list)
{
    Liste P;
    P = list;
    while (P != NULL)
    {
        printf("%d\t", P->val);
        P = P->suiv;
    }
    printf("\n");
}

int main(void)
{
    Liste myList;

    createList(&myList, 5);
    printList(myList);

    return 0;
}
