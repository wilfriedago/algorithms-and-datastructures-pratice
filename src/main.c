#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

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
{
#ifdef _WIN32
    system("cls");
#endif

#ifdef __unix__
    system("clear");
#endif
}

/**
 * @brief Procédure permettant de faire une pause la console
 */
void pauseConsole()
{
#ifdef _WIN32
    system("pause");
#endif

#ifdef __unix__
    system("sleep 2");
#endif
}

/**
 * @brief Procédure permettant d'afficher le menu du jeu
 */
void displayMenu()
{
    clearConsole();
    printf("**********************************\n*        MENU DU PROGRAMME       *\n**********************************\n\n 0. Afficher la liste\n 1. Créer une liste chaînée d'entier\n 2. Ajouter un élément en tête de liste\n 3. Ajouter un élément en queue de liste\n 4. Tier la liste\n 5. Supprimer un élément de la liste\n 6. Supprimer les doublons de la liste\n 7. Supprimer le dernier élément de la liste\n 8. Fusionner deux listes\n 9. Inverser la liste\n10. Vérifier si une liste est un palindrome\n11. Quitter le programme\n");
}

/**
 * @brief Fonction permettant de lire une caractère saisie à la console
 * @param message Message à afficher dans la console
 * @return int
 */
int readNumber(char *message)
{
    int choice;
    printf("%s", message);
    scanf("%d", &choice);
    return choice;
}

/**
 * Fonction permettant de vérifier si un nombre est compris dans un intervalle
 * @param number Valeur à tester
 * @param min Valeur minimum
 * @param max Valeur maximale
 */
bool isBetween(int number, int min, int max)
{
    return (number >= min && number <= max) ? true : false;
}

/**
 * @brief Fonction permettant de vérifier l’existence d'une liste.
 * @param list Liste passé en paramètre par valeur.
 */
bool listExist(Liste list)
{
    return list != NULL ? true : false;
}

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

int main()
{
    int choice = 0;
    int size = 0;
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
                    int c = readNumber("\n\nVoulez vous vraiment poursuivre cette opération ? Taper 1 pour Oui, ou 0 pour Non : ");

                    if (c == 0)
                        break; // On passe l'étape si l'utilisateur choisir de ne pas recréer une nouvelle liste.
                    else if (c == 1)
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
