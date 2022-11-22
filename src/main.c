#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include "../libs/utilitaires.h" // Appel des fonctions de la bibliothèque utilitaires.h (clearConsole, pauseConsole, displayMenu, readLine, isNumber, toNumber)

typedef struct Cellule Cellule; // Déclaration de la structure Cellule

struct Cellule
{
    int val;
    Cellule *suiv;
    Cellule *prec;
}; // Définition de la structure Cellule

typedef Cellule *Liste; // Définition de la structure de la liste

/**
 * @brief Procédure permettant de nettoyer le contenu de la console
 */
void clearConsole()

#ifdef __unix__
    system("clear");
#endif
}

/**
 * @brief Procédure permettant de faire une pause la console
 */
void pauseConsole()

#ifdef __unix__
    system("sleep 2");
#endif
}

/**
 * @brief Procédure permettant d'afficher le menu du jeu
 */
void displayMenu()

/**
 * @brief Fonction permettant de lire une caractère saisie à la console
 * @param message Message à afficher dans la console
 */
int readNumber(char *message)

/**
 * Fonction permettant de vérifier si un nombre est compris dans un intervalle
 * @param number Valeur à tester
 * @param min Valeur minimum
 * @param max Valeur maximale
 */
bool isBetween(int number, int min, int max)

/**
 * @brief Fonction permettant de vérifier l’existence d'une liste.
 * @param list Liste passé en paramètre par valeur.
 */
bool listExist(Liste list)

/**
 * @brief Fonction permettant d'initialiser une liste à null.
 * @param list Liste passé en paramètre par variable.
 */
void initList(Liste *list)
{
    *list = NULL;
}

/**
 * @brief Fonction permettant de créer une liste chaînée d'une taille donnée
 * @param list Liste passé en paramètre par variable
 * @param size Taille de la liste
 */
void createList(Liste *list, int size)
{
    Liste P = NULL;
    Liste Q = NULL;
    int i = 0;

    for (i = 0; i < size; i++)
    {
        P = (Liste)malloc(sizeof(Cellule));
        P->val = readNumber("\nSaisissez un nombre entier : ");
        P->suiv = NULL;
        P->prec = NULL;

        if (*list == NULL)
        {
            *list = P;
            Q = P;
        }
        else
        {
            Q->suiv = P;
            P->prec = Q;
            Q = P;
        }
    }
}

/**
 * @brief Procédure permettant d'afficher une liste
 * @param list Liste passé en paramètre par valeur
 */
void printList(Liste list)
{
    Liste P = list;

    while (P != NULL)
    {
        printf("%d - ", P->val);
        P = P->suiv;
    }
}

/**
 * @brief Procédure permettant d'ajouter un élément en tête de liste
 * @param list Liste passé en paramètre par variable
 * @param value Valeur du nouveau noeud
 */
void addHead(Liste *list, int value)
{
    Liste P = (Liste)malloc(sizeof(Cellule));

    if (P == NULL)
        exit(EXIT_FAILURE);

    P->val = value;
    P->suiv = *list;
    P->prec = NULL;

    (*list)->prec = P;

    *list = P;
}

/**
 * @brief Procédure permettant d'ajouter un élément en queue de liste
 */
void addTail(Liste *list, int value)
{
    Liste P = (Liste)malloc(sizeof(Cellule));

    if (P == NULL)
        exit(EXIT_FAILURE); // Échec de l'allocation en mémoire

    P->val = value;
    P->suiv = NULL;
    P->prec = NULL;

    if (*list == NULL)
    {
        *list = P;
    }
    else
    {
        Cellule *Q = *list;
        while (Q->suiv != NULL)
        {
            Q = Q->suiv;
        }
        Q->suiv = P;
        P->prec = Q;
    }
}

/**
 * @brief Procédure permettant de trier une liste
 * @param list Liste passé en paramètre par variable
 */
void sortList(Liste *list)
{
    Cellule *P = *list;
    Cellule *Q;

    while (P != NULL)
    {
        Q = P->suiv;
        while (Q != NULL)
        {
            if (P->val > Q->val)
            {
                int temp = P->val;
                P->val = Q->val;
                Q->val = temp;
            }
            Q = Q->suiv;
        }
        P = P->suiv;
    }
}

/**
 * @brief Procédure permettant de supprimer un élément donné de la liste
 * @param list Liste passé en paramètre par variable.
 * @param value Valeur de la cellule qu'on veux supprimer.
 */
bool deleteCell(Liste *list, int value)
{
    Cellule *P = *list;

    while (P != NULL)
    {
        if (P->val == value)
        {
            if (P->prec == NULL) // Suppression à la tête de la liste
            {
                *list = P->suiv;
                P->suiv->prec = NULL;
            }
            else if (P->suiv == NULL) // Suppression à la queue de la liste
            {
                P->prec->suiv = NULL;
            }
            else
            {
                P->prec->suiv = P->suiv;
                P->suiv->prec = P->prec;
            }
            free(P);
            return true; // On retourne vrai si la suppression c'est réalisé
        }
        P = P->suiv;
    }
    return false; // On retourne faux si il n'y a pas eu de suppression
}

int main()
{
    int choice = 0;
    int val, size = 0;
    Liste list = NULL;

    do
    {
        // Comment from Codesspaces
        displayMenu();
        choice = readNumber("\nVotre choix : ");

        if (isBetween(choice, 0, 11))
        {
            switch (choice)
            {
            case 0:
                if (listExist(list))
                    printList(list);
                else
                    printf("Rien à afficher ! Liste non initialisé !\n");

                break;
            case 1:
                if (listExist(list))
                {
                    printf("Une liste existe déjà !\nCréer une nouvelle liste revient à écraser les valeurs de cette liste existante");
                    val = readNumber("\n\nVoulez vous vraiment poursuivre cette opération ? Taper 1 pour Oui, ou 0 pour Non : ");

                    if (val == 0)
                        break; // On passe l'étape si l'utilisateur choisir de ne pas recréer une nouvelle liste.
                    else if (val == 1)
                        initList(&list); // On réinitialise la liste si l'utilisateur décide de recréer la liste.
                }
                createList(&list, readNumber("\nTaille de la liste : "));
                break;
            case 2:
                if (listExist(list))
                    addHead(&list, readNumber("\nValeur à ajouter en tête de liste : "));
                else
                    printf("Impossible d'ajouter en tête ! Liste non initialisé !\n");
                break;
            case 3:
                if (listExist(list))
                    addTail(&list, readNumber("\nValeur à ajouter en queue de liste : "));
                else
                    printf("Impossible d'ajouter en queue ! Liste non initialisé !\n");
                break;
            case 4:
                if (listExist(list))
                    sortList(&list);
                else
                    printf("Impossible de trier la liste ! Liste non initialisé !\n");
                break;
            case 5:
                if (listExist(list))
                {
                    val = readNumber("\nValeur à supprimer de la liste : ");
                    printf((deleteCell(&list, val)) ? "\nSuppression effectuée avec succès !" : "\nÉchec de la suppression ! %d ne se trouve pas dans la liste", val);
                }
                else
                    printf("Impossible d'effectué cette opération. Liste non initialisé !\n");
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                printf("Le programme va s'arrêter !\n");
                break;
            }

            pauseConsole();
        }
        else
        {
            printf("Choix invalide ! Veuillez saisir un nombre entre 1 et 11.\n\n");
        }

    } while (choice != 11);

    return EXIT_SUCCESS;
}
