#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fonction pour créer une matrice aléatoire
void creation_matrice(int dim, int matrix[dim][dim]) {
    srand(time(NULL));
    int i;
    int j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}
// Fonction pour sauvegarder la matrice en binaire
void saveMatriceBinaire(int dim, int matrix[dim][dim], const char *filename) {
    FILE *file = fopen(filename, "wb");
    int i;
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier binaire");
        exit(EXIT_FAILURE);
    }
    fwrite(&dim, sizeof(int), 1, file);
    for (i = 0; i < dim; i++) {
        fwrite(matrix[i], sizeof(int), dim, file);
    }
    fclose(file);
}
// Fonction pour sauvegarder la matrice en texte
void saveMatriceTexte(int dim, int matrix[dim][dim], const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;
    int j;
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier texte");
        exit(EXIT_FAILURE);
        if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier texte");
        exit(EXIT_FAILURE);
    }
    int dim = 0;
    while (fgetc(file) != '\n') dim++; // Déterminer la dimension
    rewind(file);
    int matrix[dim][dim];
    int i;
    int j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    printf("Matrice chargée depuis le fichier texte:\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char *argv[]) {
    int dim = 0;
    char *filename = NULL;
    int create = 0, display = 0, binary = 1; // Mode binaire par défaut
    int i;
    
    // Gestion des arguments de la ligne de commande
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            create = 1;
        } else if (strcmp(argv[i], "-a") == 0) { display = 1;
        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            dim = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-b") == 0) {
            binary = 1;
        } else if (strcmp(argv[i], "-t") == 0) {
            binary = 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            filename = argv[++i];
        }
    }
    // Vérification des paramètres
    if (filename == NULL) {
        fprintf(stderr, "Le nom du fichier est requis (-f).\n");
        return EXIT_FAILURE;
    }

    if (create) {
        if (dim <= 0) {
            fprintf(stderr, "La dimension de la matrice (-d) doit être spécifiée.\n");
            return EXIT_FAILURE;
        }
int matrix[dim][dim];
        creation_matrice(dim, matrix);
        if (binary) {
            saveMatriceBinaire(dim, matrix, filename);
        } else {
            saveMatriceTexte(dim, matrix, filename);
        }
    }

    if (display) {
        if (binary) {
           (filename);
           l_aMatriceBinaire(filename);
        } else {
            l_aMatriceTexte(filename);
        }
    }
   return EXIT_SUCCESS;
}