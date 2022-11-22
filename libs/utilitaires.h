#include <stdbool.h>
#ifndef UTILITAIRES_H
#define UTILITAIRES_H

/**
 * @brief Procédure permettant de nettoyer le contenu de la console.
 */
void clearConsole();

/**
 * @brief Procédure permettant de faire une pause la console.
 */
void pauseConsole();

/**
 * @brief Procédure permettant d'afficher le menu du programme.
 */
void displayMenu();

/**
 * @brief Fonction permettant de lire les entrées de l'utilisateur.
 */
char *readLine(char *message);

/**
 * @brief Fonction permettant de vérifier si une chaîne de caractère est un nombre.
 */
bool isNumber(char *str);

/**
 * @brief Fonction permettant de convertir une chaîne de caractère en nombre.
 */
int toNumber(char *str);

#endif
