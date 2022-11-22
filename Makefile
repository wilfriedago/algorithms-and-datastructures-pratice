# Makefile pour la compilation du projet. 

COMPILER_GCC=gcc # Compilateur GCC
COMPILER_CLANG=clang # Compilateur CLANG

TARGET=./build/main 

SOURCE=./src/main.c # Fichier source du projet

# Compilation du projet
all:
	$(COMPILER_GCC) $(SOURCE) -o $(TARGET)

# Compilation du projet avec GCC
gcc:
	$(COMPILER_GCC) $(SOURCE) -o $(TARGET)

# Compilation du projet avec CLANG
clang:
	$(COMPILER_CLANG) $(SOURCE) -o $(TARGET)

# Nettoyage du projet
clean:
	rm $(TARGET)

# Exécution du projet
run:
	$(TARGET)
