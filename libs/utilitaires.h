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
 * @brief Procédure permettant d'afficher le menu du programme
 */
void displayMenu()
{
  printf("**********************************\n*        MENU DU PROGRAMME       *\n**********************************\n\n 0. Afficher la liste\n 1. Créer une liste chaînée d'entier\n 2. Ajouter un élément en tête de liste\n 3. Ajouter un élément en queue de liste\n 4. Tier la liste\n 5. Supprimer un élément de la liste\n 6. Supprimer les doublons de la liste\n 7. Supprimer le dernier élément de la liste\n 8. Fusionner deux listes\n 9. Inverser la liste\n10. Vérifier si une liste est un palindrome\n11. Quitter le programme\n");
}
