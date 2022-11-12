#include <stdio.h>
#include <stdlib.h>

//#include <graphics.h>

#define POS_X 1
#define POS_Y 1

// Fonctions utilitaires system("cls"); system("pause");
/**
 * @brief Fonction permettant d'afficher le menu du jeu
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
char readChar(char *message)
{
    char choice;
    printf("%s", message);
    scanf("%s", &choice);
    return choice;
}

int main(void)
{
    printf("Hello world !\n");
    return 0;
}
