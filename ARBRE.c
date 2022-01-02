#include "ARBRE.h"

struct ARBRE* creerNoeud(int cle, char *nom) {
    struct ARBRE* nouveau = (struct ARBRE*) malloc(sizeof(struct ARBRE));
    nouveau->cle=cle;
    strcpy(nouveau->nom,nom);
    nouveau->gauche=nouveau->droite=NULL;
    return nouveau;
}

struct ARBRE* insert(struct ARBRE* a, int cle, char *nom){
    if(a==NULL){
        return creerNoeud(cle,nom);
    }
    if(cle<a->cle){
        a->gauche= insert(a->gauche, cle, nom);
    }
    else if(cle>a->cle){
        a->droite= insert(a->droite, cle, nom);
    }
    return a;
}

struct ARBRE* saisiefichier(struct ARBRE* a, char *fichier) {
    FILE *f;
    int size, cle;
    char nom[50];
    f = fopen(strncat(fichier, ".txt", strlen(fichier)+4), "r");//ajout de ".txt" au nom du fichier
    if(f!=NULL) {
        fscanf(f, "%d", &size);
        printf("%d\n", size);
        for (int i = 0; i<size; i++) {
            fscanf(f, "%s", nom);
            printf("Nom de l'article : %s\n", nom);
            fscanf(f, "%d", &cle);
            printf("ID de l'article : %d\n", cle);
            a=insert(a,cle,nom);
        }
    }
    fclose(f);
    return a;
}

struct ARBRE* min(struct ARBRE* a){
    struct ARBRE* actuel = a;
    while (actuel && actuel->gauche != NULL)
        actuel = actuel->gauche;
    return actuel;
}

struct ARBRE* del(struct ARBRE* a, int cle){
    if (a == NULL) return a;
    if (cle < a->cle)
        a->gauche = del(a->gauche, cle);
    else if (cle > a->cle)
        a->droite = del(a->droite, cle);
    else {
        if (a->gauche == NULL) {
            struct ARBRE* temp = a->droite;
            free(a);
            printf("Supprimer avec succes\n");
            return temp;
        }
        else if (a->droite == NULL) {
            struct ARBRE* temp = a->gauche;
            free(a);
            printf("Supprimer avec succes\n");
            return temp;
        }
        struct ARBRE* temp = min(a->droite);
        a->cle = temp->cle;
        a->droite = del(a->droite, temp->cle);
    }
}

void recherche(struct ARBRE* a, int cle) {
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
    printf("Non trouve");
}

int checksearch(struct ARBRE* a, int cle) {
    while(a){
        if(cle==a->cle){
            return 1;
        }
        if(cle>a->cle){
            a=a->droite;
        }
        else {
            a=a->gauche;
        }
    }
    return 0;
}

void affichage(struct ARBRE* a){
    if(!a){
        return;
    }
    if(a->gauche){
        affichage(a->gauche);
    }
    printf("ID : %d, Article : %s\n", a->cle, a->nom);
    if(a->droite){
        affichage(a->droite);
    }
}

void affichageinverse(struct ARBRE* a){
    if(!a){
        return;
    }
    if(a->droite){
        affichageinverse(a->droite);
    }
    printf("ID : %d, Article : %s\n", a->cle, a->nom);
    if(a->gauche){
        affichageinverse(a->gauche);
    }
}

void cleanBuffer(){
    int c=0;
    while(c!='\n' && c!=EOF) c = getchar();
}

int read(char *string, int lengh){
    char *positionEntree = NULL;
    if (fgets(string, lengh, stdin) != NULL)
    {
        positionEntree = strchr(string, '\n');
        if (positionEntree != NULL) *positionEntree = '\0';
        else cleanBuffer();
        return 1;
    }
    else
    {
        cleanBuffer();
        return 0;
    }
}

char* getNom(char *nom){
    return nom;
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