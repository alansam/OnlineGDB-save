
#include <stdio.h>
#include <stdlib.h>

#define LONGUEUR_MAX_MOT 100
#define NB_MAX_ETATS 5
#define NB_TAILLE_ALPHABET 10

typedef struct 
{
    int nb_etats;
    int TAILLE_ALPHABET;
    int etats_initial;
    int etat_acceptant;
    int matrice_transition[NB_MAX_ETATS][NB_TAILLE_ALPHABET];
} t_automate;

int i, j;

int automate_union(t_automate A, t_automate B)
{
    t_automate C;
    C.nb_etats = A.nb_etats + B.nb_etats;
    C.etats_initial = 0;
    C.etat_acceptant = A.etat_acceptant + B.etat_acceptant;
    C.TAILLE_ALPHABET = A.TAILLE_ALPHABET + B.TAILLE_ALPHABET;
    for (i = 0; i < C.TAILLE_ALPHABET; i++)
        printf("\t%c", 'a' + i);
    printf("\n");

    //  matrix accumulate
    for (size_t x_ = 0; x_ < NB_MAX_ETATS; ++x_) {
        for (size_t y_ = 0; y_ < NB_TAILLE_ALPHABET; ++y_) {
            C.matrice_transition[x_][y_] = A.matrice_transition[x_][y_] + B.matrice_transition[x_][y_];
        }
    }

    for (i = 0; i < C.nb_etats; i++)
    {
        printf("E%d", i);
        for (j = 0; j < C.TAILLE_ALPHABET; j++)
            printf("\tE%d", C.matrice_transition[i][j]);
        printf("\n");


    }
    printf("\n");

    return EXIT_SUCCESS;
}

int main()
{
    printf("Hello World\n");

    t_automate A = {
        2, 4, 5, 1,
        {
            { 10, 11, 12, 13, 14, },
            { 20, 21, 22, 23, 24, },
        },
    };
    t_automate B = {
        3, 4, 5, 2,
        {
            { 10, 11, 12, 13, 14, },
            { 20, 21, 22, 23, 24, },
            { 30, 31, 32, 33, 34, },
        },
    };

    automate_union(A, B);

    return 0;
}

