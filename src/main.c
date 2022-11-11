#include <stdio.h>
#include <stdlib.h>

#define POS_X 1
#define POS_Y 1

// Fonctions utilitaires system("cls"); system("pause");

// FIXME: Make all the red disappear
/**
 * @brief Fonction pour se positionner à un endroit (x,y) dans la console
 * @param x Position x
 * @param y Position y
 */
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

// FIXME: le paramètre style à pour valeur par défaut la chaîne de caractère plain
/**
 * @brief Fonction pour dessiner un rectangle dans la console
 * @param x Position x
 * @param y Position y
 * @param lon longueur du rectangle
 * @param lar largeur du rectangle
 */
void rectangle(int x, int y, int lon, int lar, char *style = 'plain')
{
    int i, pas = 1;

    if (style == 'dotted')
        pas = 2;

    gotoxy(x, y);
    printf("%c", 218);

    gotoxy(x + lon, y);
    printf("%c", 191);

    gotoxy(x, y + lar);
    printf("%c", 192);

    gotoxy(x + lon, y + lar);
    printf("%c", 217);

    for (i = 1; i < lon; i += pas)
    {
        gotoxy(x + i, y);
        printf("%c", 196);

        gotoxy(x + i, y + lar);
        printf("%c", 196);
    }

    for (i = 1; i < lar; i += pas)
    {
        gotoxy(x, y + i);
        printf("%c", 179);

        gotoxy(x + lon, y + i);
        printf("%c", 179);
    }
}

// TODO: Create the appropriate menu for the exercice
/**
 * @brief Fonction permettant d'afficher le menu du jeu
 */
void displayMenu()
{
    rectangle(POS_X - 1, POS_Y - 1, 25, 2);
    rectangle(POS_X - 1, POS_Y + 2, 25, 5);
    rectangle(POS_X - 1, POS_Y + 8, 25, 2);

    gotoxy(POS_X + 10, POS_Y);
    printf("MENU");

    gotoxy(POS_X + 1, POS_Y + 3);
    printf("1- Lancer une partie");

    gotoxy(POS_X + 1, POS_Y + 4);
    printf("2- Réglages");

    gotoxy(POS_X + 1, POS_Y + 5);
    printf("3- Meilleurs Scores.");

    gotoxy(POS_X + 1, POS_Y + 6);
    printf("4- Arrêter le programme.");
}

/**
 * @brief Fonction permettant de lire une saisie à la console
 * @param message Message à afficher dans la console
 * @return char*
 */
char *readLine(char *message)
{
    char *choice;
    printf("%s", message);
    return scanf("%s", &choice);
}

int main(void)
{
    printf("Hello world !\n");
    return 0;
}
