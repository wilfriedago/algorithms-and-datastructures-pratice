/**
 * @file main.c
 * @brief Implémentation d'une Liste doublement chaînée.
 *
 * @author [Wilfried Kirin AGO](https://github.com/wilfriedago)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include "../libs/utilitaires.h" // Appel des fonctions de la bibliothèque utilitaires.h (clearConsole, pauseConsole, displayMenu, readLine, isNumber, toNumber)

/**
 * @brief Structure d'une cellule de la liste.
 */
typedef struct Cellule
{
    int val;                     // Valeur de la cellule.
    struct Cellule *suiv, *prec; // Pointeurs vers les autres cellules, ou NULL.
} Cellule;

/**
 * @brief Structure d'une liste doublement chaînée.
 */
typedef Cellule *Liste;

/**
 * @brief   Function permettant de créer une liste doublement chaînée d'une seul cellule.
 * @param   valeur Valeur de la première cellule.
 * @return  *newList La liste nouvellement créer.
 */
Liste createList(int valeur);

/**
 * @brief Procédure permettant d'ajouter une cellule en tête de liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule insérer.
 */
void insertHead(Liste *liste, int valeur);

/**
 * @brief Procédure permettant d'ajouter une cellule en queue de liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule insérer.
 */
void insertTail(Liste *liste, int valeur);

/**
 * @brief Procédure permettant de trier une liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 */
void sortList(Liste *liste);

/**
 * @brief Fonction permettant de supprimer une cellule de la liste ayant une valeur donné.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule à supprimer.
 * @return true : Si la cellule à été supprimer.
 * @return false : Si la cellule n'a pas pu être supprimer.
 */
bool deleteCell(Liste *liste, int valeur);

/**
 * @brief Procédure permettant de supprimer les doublons (Cellules ayant la même valeur) dans une liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 */
void deleteDuplicates(Liste *liste);

/**
 * @brief Fonction permettant de supprimer la dernière cellule d'une liste.
 * @param liste doublement chaînée passée en paramètre par variable.
 * @return true : Si la cellule a été supprimer.
 * @return false : Si la cellule n'a pas pu être supprimer.
 */
bool deleteLastCell(Liste *liste);

/**
 * @brief Procédure permettant de fusionner deux listes doublement chaînée.
 * @param liste1 Première liste à fusionner.
 * @param liste2 Deuxième liste à fusionner.
 */
void mergeLists(Liste *liste1, Liste *liste2);

/**
 * @brief Procédure permettant de renverser une liste doublement chaînée.
 * @param liste Liste chaînée passée en paramètre par variable.
 */
void reverseList(Liste *liste);

/**
 * @brief Fonction permettant de vérifier si une liste est un palindrome.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 */
bool listIsPalindrome(Liste *liste);

/**
 * @brief Procédure permettant d'afficher une liste.
 * @param liste Liste doublement chaînée passé en paramètre par valeur.
 */
void printList(Liste liste);

/**
 * @brief Function principale du programme.
 *
 * @return EXIT_SUCCESS
 */
int main()
{
    int choice, val, taille;
    Liste maListe = NULL;

    do
    {
        displayMenu();
        choice = toNumber(readLine("\nVotre choix : "));

        if (choice >= 0 && choice <= 11)
        {
            switch (choice)
            {
            case 0:
                if (maListe != NULL)
                    printList(maListe);
                else
                    printf("Rien à afficher ! La liste est vide !\n");

                break;
            case 1:
                if (maListe != NULL)
                {
                    printf("Une liste existe déjà !\nCréer une nouvelle liste revient à écraser la liste existante.");
                    if (readLine("\nVoulez-vous continuer ? (O/N) : ")[0] == 'O')
                    {
                        free(maListe);
                        maListe = NULL;
                    }
                    else
                    {
                        printf("\nOpération annulée !\n");
                        break;
                    }
                }

                taille = toNumber(readLine("\nTaille de la liste : "));

                if (taille > 0)
                {
                    maListe = createList(toNumber(readLine("Valeur de la première cellule : ")));
                    for (int i = 1; i < taille; i++)
                        insertTail(&maListe, toNumber(readLine("Valeur de la cellule suivante : ")));
                }
                else
                {
                    printf("La taille de la liste doit être supérieur à 0 !\n");
                    break;
                }

                printf("Liste créée avec succès !\n");
                break;
            case 2:
                if (maListe != NULL)
                {
                    val = toNumber(readLine("\nValeur de la cellule à insérer : "));
                    insertHead(&maListe, val);
                    printf("Insertion en tête réussie !\nNouvelle liste : ");
                    printList(maListe);
                }
                else
                    printf("Impossible d'insérer un élément en tête, la liste n'a pas été créer !\n");

                break;
            case 3:
                if (maListe != NULL)
                {
                    val = toNumber(readLine("\nValeur de la cellule à insérer : "));
                    insertTail(&maListe, val);
                    printf("Insertion en queue réussie !\nNouvelle liste : ");
                    printList(maListe);
                }
                else
                    printf("Impossible d'insérer un élément en queue, la liste n'a pas été créer !\n");

                break;
            case 4:
                if (maListe != NULL)
                {
                    sortList(&maListe);
                    printf("Tri réussi !\nNouvelle liste : ");
                    printList(maListe);
                }
                else
                    printf("Impossible d'effectuer le trie, la liste n'a pas été créer !\n");

                break;
            case 5:
                if (maListe != NULL)
                {
                    val = toNumber(readLine("Valeur de la cellule à supprimer : "));

                    if (deleteCell(&maListe, val))
                        printf("Suppression réussie !\nNouvelle liste : ");
                    else
                        printf("Impossible de supprimer la cellule, elle n'existe pas !\nNouvelle liste : ");

                    printList(maListe);
                }
                else
                    printf("Impossible de supprimer une cellule, la liste n'a pas été créer !\n");

                break;
            case 6:
                if (maListe != NULL)
                {
                    deleteDuplicates(&maListe);
                    printf("Suppression des doublons réussie !\nNouvelle liste : ");
                    printList(maListe);
                }
                else
                    printf("Impossible de supprimer les doublons, la liste n'a pas été créer !\n");

                break;
            case 7:
                if (maListe != NULL)
                {
                    if (deleteLastCell(&maListe))
                        printf("Suppression de la dernière cellule réussie !\nNouvelle liste : ");
                    else
                        printf("Impossible de supprimer la dernière cellule, la liste est vide !\nNouvelle liste : ");

                    printList(maListe);
                }
                else
                    printf("Impossible de supprimer la dernière cellule, la liste n'a pas été créer !\n");

                break;
            case 8:
                // TODO : Implémenter la fonctionnalité
                break;
            case 9:
                if (maListe != NULL)
                {
                    reverseList(&maListe);
                    printf("Renversement de la liste réussi !\nNouvelle liste : ");
                    printList(maListe);
                }
                else
                    printf("Impossible de renverser la liste, la liste n'a pas été créer !\n");

                break;
            case 10:
                if (maListe != NULL)
                {
                    if (listIsPalindrome(&maListe))
                        printf("La liste est un palindrome !\n");
                    else
                        printf("La liste n'est pas un palindrome !\n");
                }
                else
                    printf("Impossible de vérifier si la liste est un palindrome, la liste n'a pas été créer !\n");
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

/**
 * @brief   Function permettant de créer une liste doublement chaînée d'une seul cellule.
 * @param   valeur Valeur de la première cellule.
 * @return  *newList La liste nouvellement créer.
 */
Liste createList(int valeur)
{
    Liste newList = (Liste)malloc(sizeof(Cellule));

    if (newList == NULL)
    {
        printf("Erreur d'allocation mémoire !\n");
        exit(EXIT_FAILURE);
    }

    newList->val = valeur;
    newList->suiv = NULL;
    newList->prec = NULL;
    return newList;
}

/**
 * @brief Procédure permettant d'ajouter une cellule en tête de liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule insérer.
 */
void insertHead(Liste *liste, int valeur)
{
    // Cas d'une liste vide.
    if (*liste == NULL)
    {
        (*liste) = createList(valeur);
        return;
    }

    Liste newCell = (Liste)malloc(sizeof(Cellule));

    if (newCell == NULL)
    {
        printf("Erreur d'allocation mémoire !\n");
        exit(EXIT_FAILURE);
    }

    newCell->val = valeur;
    newCell->suiv = *liste;
    newCell->prec = NULL;

    (*liste)->prec = newCell;
    *liste = newCell;
}

/**
 * @brief Procédure permettant d'ajouter une cellule en queue de liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule insérer.
 */
void insertTail(Liste *liste, int valeur)
{
    // Cas d'une liste vide.
    if (*liste == NULL)
    {
        (*liste) = createList(valeur);
        return;
    }

    Liste newCell = (Liste)malloc(sizeof(Cellule));

    if (newCell == NULL)
    {
        printf("Erreur d'allocation mémoire !\n");
        exit(EXIT_FAILURE);
    }

    newCell->val = valeur;
    newCell->suiv = NULL;

    Liste tempCell = *liste;

    while (tempCell->suiv != NULL)
        tempCell = tempCell->suiv;

    tempCell->suiv = newCell;
    newCell->prec = tempCell;
}

/**
 * @brief Procédure permettant de trier une liste.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 */
void sortList(Liste *liste)
{
    Liste tempCell = *liste;
    int tempVal;
    bool isSorted = false;

    do
    {
        isSorted = true; // On suppose que la liste est triée.
        tempCell = *liste;

        while (tempCell->suiv != NULL)
        {
            if (tempCell->val > tempCell->suiv->val)
            {
                tempVal = tempCell->val;
                tempCell->val = tempCell->suiv->val;
                tempCell->suiv->val = tempVal;
                isSorted = false; // La liste n'est pas triée.
            }

            tempCell = tempCell->suiv;
        }

    } while (!isSorted); // Tant que la liste n'est pas triée.
}

/**
 * @brief Fonction permettant de supprimer une cellule de la liste ayant une valeur donné.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 * @param valeur Valeur de la cellule à supprimer.
 * @return true : Si la cellule à été supprimer.
 * @return false : Si la cellule n'a pas pu être supprimer.
 */
bool deleteCell(Liste *liste, int valeur)
{
    Liste tempCell = *liste;

    while (tempCell != NULL)
    {
        if (tempCell->val == valeur)
        {
            if (tempCell->prec == NULL) // Cas où la cellule à supprimer est en tête de liste.
            {
                *liste = tempCell->suiv;
                (*liste)->prec = NULL;
            }

            else if (tempCell->suiv == NULL) // Cas où la cellule à supprimer est en queue de liste.
                tempCell->prec->suiv = NULL;

            else // Cas où la cellule à supprimer se trouve  dans la liste.
            {
                tempCell->prec->suiv = tempCell->suiv;
                tempCell->suiv->prec = tempCell->prec;
            }

            free(tempCell);
            return true;
        }

        tempCell = tempCell->suiv;
    }

    return false;
}

/**
 * @brief Procédure permettant de supprimer les doublons d'une liste
 * @param liste Liste passé en paramètre par variable
 */
// TODO : Revoir la logique.
void deleteDuplicates(Liste *liste)
{
    Liste tempCell = *liste;

    while (tempCell != NULL)
    {
        if (tempCell->suiv != NULL)
        {
            if (tempCell->val == tempCell->suiv->val)
            {
                if (tempCell->suiv->suiv != NULL)
                {
                    tempCell->suiv = tempCell->suiv->suiv;
                    tempCell->suiv->prec = tempCell;
                }
                else
                    tempCell->suiv = NULL;
            }
        }

        tempCell = tempCell->suiv;
    }
}

/**
 * @brief Fonction permettant de supprimer la dernière cellule d'une liste.
 * @param liste doublement chaînée passée en paramètre par variable.
 * @return true : Si la cellule a été supprimer.
 * @return false : Si la cellule n'a pas pu être supprimer.
 */
bool deleteLastCell(Liste *liste)
{
    Liste tempCell = *liste;

    if (tempCell == NULL) // Cas d'une liste vide.
        return false;

    while (tempCell->suiv != NULL) // On parcours la liste jusqu'à la dernière cellule.
        tempCell = tempCell->suiv;

    if (tempCell->prec == NULL) // Cas où la liste ne contient qu'une seule cellule.
        *liste = NULL;

    else                             // Cas où la liste contient plusieurs cellules.
        tempCell->prec->suiv = NULL; // On supprime la dernière cellule.

    free(tempCell);
    return true;
}

/**
 * @brief Procédure permettant de fusionner deux listes doublement chaînée.
 * @param liste1 Première liste à fusionner.
 * @param liste2 Deuxième liste à fusionner.
 */
void mergeLists(Liste *liste1, Liste *liste2)
{
    Liste tempCell = *liste2;

    while (tempCell != NULL)
    {
        insertTail(liste1, tempCell->val); // On insère les cellules de la deuxième liste dans la première.
        tempCell = tempCell->suiv;
    }
}

/**
 * @brief Procédure permettant de renverser une liste doublement chaînée.
 * @param liste Liste chaînée passée en paramètre par variable.
 */
void reverseList(Liste *liste)
{
    Liste tempCell = *liste;
    Liste tempCell2 = NULL;

    while (tempCell != NULL)
    {
        tempCell2 = tempCell->prec;      // On stocke la cellule précédente.
        tempCell->prec = tempCell->suiv; // On inverse les pointeurs.
        tempCell->suiv = tempCell2;      // On inverse les pointeurs.
        tempCell = tempCell->prec;       // On avance dans la liste.
    }

    if (tempCell2 != NULL)        // On vérifie que la liste n'est pas vide.
        *liste = tempCell2->prec; // On affecte la nouvelle tête de liste.
}

/**
 * @brief Fonction permettant de vérifier si une liste est un palindrome.
 * @param liste Liste doublement chaînée passée en paramètre par variable.
 */
bool listIsPalindrome(Liste *liste)
{
    if (*liste == NULL) // Cas d'une liste vide.
        return false;
    else if ((*liste)->suiv == NULL) // Cas d'une liste contenant une seule cellule.
        return true;
    else
    {
        Liste tempCell = *liste;
        Liste tempCell2 = *liste;
        int size = 0;

        while (tempCell != NULL) // On parcours la liste pour compter le nombre de cellules.
        {
            size++;
            tempCell = tempCell->suiv;
        }

        for (int i = 0; i < size / 2; i++) // On parcours la moitié de la liste.
        {
            if (tempCell2->val != tempCell->val) // On vérifie si les valeurs sont identiques.
                return false;

            tempCell2 = tempCell2->suiv; // On avance dans la première moitié de la liste.
            tempCell = tempCell->prec;   // On recule dans la deuxième moitié de la liste.
        }

        return true;
    }
}

/**
 * @brief Procédure permettant d'afficher une liste.
 * @param liste Liste doublement chaînée passé en paramètre par valeur.
 */
void printList(Liste liste)
{
    printf("%d", liste->val);
    liste = liste->suiv;

    while (liste != NULL)
    {
        printf(" - %d", liste->val);
        liste = liste->suiv;
    }
    printf("\n");
}
