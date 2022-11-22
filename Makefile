# Makefile pour la compilation du projet. 

COMPILER_GCC=gcc # Compilateur GCC
COMPILER_CLANG=clang # Compilateur CLANG

TARGET=./build/main  # Nom de l'exécutable

SOURCE=./src/main.c # Fichier source du projet

LIBS=./libs/utilitaires.c # Librairies à lier

# Compilation du projet
all:
	$(COMPILER_GCC) $(SOURCE) $(LIBS) -o $(TARGET) && clear  && $(TARGET)

# Compilation du projet avec GCC
gcc:
	$(COMPILER_GCC) $(SOURCE) $(LIBS) -o $(TARGET) && clear  && $(TARGET)

# Compilation du projet avec CLANG
clang:
	$(COMPILER_CLANG) $(SOURCE) $(LIBS) -o $(TARGET) && clear  && $(TARGET)

# Nettoyage du projet
clean:
	rm $(TARGET)

# Exécution du projet
run:
	$(TARGET)
