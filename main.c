#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define N 100

//typedef int ARBRE[N] ;
//ARBRE a;

typedef struct _Noeud {
    int val;
    struct _Noeud * fg, *fd;
} NOEUD;

typedef struct article{
    int ID;
    char Nom[];
} ARTICLE;

ARTICLE articles[100];

typedef NOEUD * ARBRE;
ARBRE a;

void afficher(ARBRE a) {
    if (a) {
        afficher(a->fg);
        printf("%d",a->val);
        afficher(a->fd);
    }
}

ARBRE creerNoeud(int newVal) {
    ARBRE nouveau = (ARBRE) malloc(sizeof(NOEUD));
    if (nouveau) {
        nouveau->val=newVal;
        nouveau->fg=nouveau->fd=NULL;
    }
    return nouveau;
}

//insérer n dans l'arbre a
ARBRE inserer(int n,ARBRE A) {
    //si a vide, créer noeud avec n et le renvoyer
    if (/*a==NULL*/!a) {
        return creerNoeud(n);
    }
    else {
        if (n <= a->val) {
            a->fg = inserer(n, a->fg);
        } else {
            a->fd = inserer(n, a->fd);
        }
    }
    return a;
}

ARTICLE saisie (int n){
    int i;
    for(i=0;i<n;i++) {
        printf("Nom de l'article:\n");
        scanf("%s", articles[i].Nom);
        printf("ID de l'article:\n");
        scanf("%d", articles[i].ID);
    }
    return articles;
}

int main() {
    int n;
    printf("Nombre d'articles a ajouter:\n");
    scanf("%d", &n);
    ARBRE a=NULL;
    saisie(n);
    return 0;
}
