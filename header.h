#include <stdio.h>
#include <stdlib.h>

struct Noeud {
    int cle;
    char *nom;
    struct Noeud *gauche, *droite;
};
typedef struct Noeud TNoeud;
typedef TNoeud* ARBRE;

TNoeud* CreerNoeud(int cle, char *nom);