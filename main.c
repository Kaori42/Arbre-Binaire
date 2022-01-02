#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "header.h"

typedef struct Noeud {
    int cle;
    struct Noeud *gauche;
    struct Noeud *droite;
    char *nom;
} TNoeud;

typedef TNoeud *ARBRE;

/*void afficher(ARBRE a) {
    if (a) {
        afficher(a->gauche);
        printf("%d",a->cle);
        afficher(a->droite);
    }
}*/

ARBRE creerNoeud(int cle, ARBRE gauche, ARBRE droite, char *nom) {
    ARBRE nouveau = (ARBRE) malloc(sizeof(TNoeud));
    if (nouveau) {
        nouveau->cle=cle;
        nouveau->gauche=gauche;
        nouveau->droite=droite;
        nouveau->nom=nom;
    }
    return nouveau;
}

//insérer n dans l'arbre a
ARBRE inserer(ARBRE a, int n) {
    //si a vide, créer noeud avec n et le renvoyer
    if (!a) {
        return creerNoeud(n, NULL, NULL, NULL);
    }
    else {
        if (n < a->cle) {
            a->gauche= inserer(a->gauche, n);
        } else {
            a->droite= inserer(a->droite, n);
        }
    }
    return a;
}

void saisie(ARBRE a, int n){//fonction jumelle de inserer juste pour test
    ARBRE tmp=NULL;
    //le choix de l'ID sera proposé avant l'execution de la fonction, same pour inserer
    if(!a) {
        tmp = malloc(sizeof(ARBRE));
        tmp->gauche=tmp->droite=NULL;
        printf("Nom de l'article:\n");
        scanf("%s", tmp->nom);
        tmp->cle=n;
        a=tmp;
        return;
    }

    if(n < a->cle){
        saisie(a->gauche, n);
    } else if (n > a->cle){
        saisie(a->droite, n);
    }
}

ARBRE saisiefichier(char *fichier, ARBRE a) {//PAS BON//A EDIT //meme pb que saisie, genre la fonction est techniquement bonne mais pas pour les arbres
    FILE *f;
    int size;
    f = fopen(strncat(fichier, ".txt", 4), "r");//normalement ça ajoute .txt au nom du fichier
    if(f!=NULL) {
        fscanf(f, "%d", &size);
        printf("%d\n", size);
        for (int i = 0; i<size; i++) {
            //PAS FINI
            a= creerNoeud();
            fscanf(f, "%s", a->nom);
            printf("Nom de l'article : %s\n", a->nom);
            fscanf(f, "%d", &a->cle);
            printf("Cle de l'article : %d\n", a->cle);
        }
    }
    fclose(f);
    return a;
}

ARBRE suppression(ARBRE a, int cle) {
    while(a){
        if(cle==a) ;
    }
    return a;
}

void recherche(ARBRE a, int cle) {
    while(a){
        if(cle==a->cle){
            printf("Nom de l'article : %s\n", a->nom);
        }
        if(cle>a->cle){
            a=a->droite;
        }
        else {
            a=a->gauche;
        }
    }
}

void ajout(ARBRE *a, int cle){

}

void affichage(ARBRE a){//MANQUE LE FICHIER
    if(!a){
        return;
    }
    if(a->gauche){
        affichage(a->gauche);
    }
    printf("Cle = %d\n Nom de l'article : %s\n", a->cle, a->nom);
    if(a->droite){
        affichage(a->droite);
    }
}

void affichageinverse(ARBRE a){
    if(!a){
        return;
    }
    if(a->droite){
        affichageinverse(a->droite);
    }
    printf("Cle = %d\n Nom de l'article : %s\n", a->cle, a->nom);
    if(a->gauche){
        affichageinverse(a->gauche);
    }
}

int main() {
    int n, X=0;
    ARBRE articles[X];
    char *typeS=NULL, *nomF=NULL;
    printf("Saisie directe ou depuis un fichier txt ? (D/F)\n");
    scanf("%s", typeS);
    if(typeS=="D") {
        printf("Combien d'articles ?\n");
        scanf("%d", &X);
        printf("Nombre d'articles a ajouter:\n");
        scanf("%d", &n);
        saisie(n, articles);
    }
    else if(typeS=="F"){
        printf("Nom du fichier ?\n");
        scanf("%s", nomF);
        saisiefichier(nomF, articles);
    }
    else
    ///ARBRE a=NULL;
    return 0;
}