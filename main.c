#include "header.h"

TNoeud* creerNoeud(int cle, char *nom) {
    TNoeud* nouveau=NULL;
    nouveau = (TNoeud*) malloc(sizeof(TNoeud));
    nouveau->cle=cle;
    nouveau->gauche=NULL;
    nouveau->droite=NULL;
    nouveau->nom=nom;
    return nouveau;
}

ARBRE inserer(ARBRE a, int cle) {
    //si a vide, créer noeud avec n et le renvoyer
    if (!a) {
        return creerNoeud(cle, NULL);
    }
    else {
        if (cle < a->cle) {
            a->gauche= inserer(a->gauche, cle);
        } else {
            a->droite= inserer(a->droite, cle);
        }
    }
    return a;
}

ARBRE insert(ARBRE a, int cle) {
    ARBRE prec;
    char *nom = NULL;
    if (!a) {
        printf("Nom de l'article:\n");
        scanf("%s", nom);
        return creerNoeud(cle, nom);
    }
    while(a){
        prec=a;
        if(cle < a->cle){
            a=a->gauche;
        }
        else {
            a=a->droite;
        }
        if (cle < prec->cle){
            prec->gauche= creerNoeud(cle, nom);
        }
        else {
            prec->droite= creerNoeud(cle, nom);
        }
    }
    return a;
}

TNoeud* insert2(ARBRE a, int cle, char *nom){
    if(a==NULL){
        return creerNoeud(cle,nom);
    }
    if(cle<a->cle){
        a->gauche= insert2(a->gauche, cle, nom);
    }
    else if(cle>a->cle){
        a->droite= insert2(a->droite, cle, nom);
    }
    return a;
}

/*ARBRE saisiefichier(char *fichier, ARBRE a) {
    FILE *f;
    int size;
    f = fopen(strncat(fichier, ".txt", strlen(fichier)+4), "r");//normalement ça ajoute .txt au nom du fichier
    if(f!=NULL) {
        fscanf(f, "%d", &size);
        printf("%d\n", size);
        for (int i = 0; i<size; i++) {
            //PAS FINI
            a= creerNoeud(tmp, NULL, NULL, NULL);
            fscanf(f, "%s", a->nom);
            printf("Nom de l'article : %s\n", a->nom);
            fscanf(f, "%d", &a->cle);
            printf("Cle de l'article : %d\n", a->cle);
        }
    }
    fclose(f);
    return a;
}*/

ARBRE suppression(ARBRE a, int cle) {
    ARBRE NoeudASuppr;
    if (a->cle==cle){
        NoeudASuppr=a;
        if (NoeudASuppr->gauche==NULL){
            return NoeudASuppr->gauche;
        }
        else{
            a=NoeudASuppr->gauche;
            while(a->gauche!=NULL){
                a=a->droite;
            }
            a->droite=NoeudASuppr->droite;
            return NoeudASuppr->gauche;
        }
        free(NoeudASuppr);
    }
    else{
        if(a->cle>cle){
            a->gauche= suppression(a->gauche,cle);
        }
        else{
            a->droite= suppression(a->droite,cle);
        }
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

void affichage(ARBRE a){
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

void aff(ARBRE a)
{
    if (a != NULL) {
        aff(a->gauche);
        printf("%d, %s \n", a->cle, a->nom);
        aff(a->droite);
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

int menu() {
    int choix;
    printf("Menu :\n");
    printf("1. Saisie directe\n");
    printf("2. Saisie depuis un fichier txt\n");
    printf("3. Suppression\n");
    printf("4. Recherche\n");
    printf("5. Affichage\n");
    printf("6. Affichage inverse\n");
    printf("7. Quitter\n");
    scanf("%d",&choix);
    return choix;
}

int main() {
    int cle, X=0, fin=0, SearchCle, DelCle;
    ARBRE articles=NULL;
    char *nomF, *nom;
    while(!fin){
        switch(menu()){
            case 1:
                printf("Combien d'articles ?\n");
                scanf("%d", &X);
                for (int i=0; i<X; i++){
                    printf("Numero de l'article a ajouter:\n");
                    scanf("%d", &cle);
                    printf("Nom de l'article:\n");
                    scanf("%s",&(*nom));
                    printf("%s\n", nom);
                    insert2(articles, cle, nom);
                }
                break;
            case 2:
                printf("Nom du fichier ?\n");
                scanf("%s", nomF);
                //saisiefichier(nomF, articles);
                break;
            case 3:
                printf("Entrer l'ID à supprimer :\n");
                scanf("%d",&DelCle);
                suppression(articles, DelCle);
                break;
            case 4:
                printf("Entrer l'ID à rechercher :\n");
                scanf("%d",&SearchCle);
                recherche(articles,SearchCle);
                break;
            case 5:
                aff(articles);
                break;
            case 6:
                affichageinverse(articles);
                break;
            case 7:
                fin=1;
                break;
            default:
                printf("Erreur de saisie");
                break;
        }
    }
    return 0;
}