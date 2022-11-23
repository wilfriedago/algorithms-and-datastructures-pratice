# Makefile pour la compilation du projet. 

COMPILER=gcc # Compilateur

TARGET=./build/main  # Nom de l'exécutable

SOURCE=./src/main.c # Fichier source du projet

LIBS=./libs/utilitaires.c # Librairies à lier

# Compilation du projet
all:
	$(COMPILER) $(SOURCE) $(LIBS) -o $(TARGET) && $(TARGET)

# Nettoyage du projet
clean:
	rm $(TARGET)

# Exécution du projet
run:
	$(TARGET)
