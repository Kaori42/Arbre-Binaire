#include "ARBRE.h"

int main() {
    struct ARBRE* articles = NULL;
    char nom[50], nomF[255];
    int cle, X=0, fin=0, SearchCle, DelCle;
    while(!fin){
        switch(menu()){
            case 1:
                printf("Nombre d'articles a saisir ?\n");
                scanf("%d", &X);
                if(X<=0){
                    printf("Erreur, nombre d'articles invalide\n");
                    break;
                }
                cleanBuffer();
                printf("Numero de l'article a ajouter:\n");
                scanf("%d", &cle);
                cleanBuffer();
                printf("Nom de l'article:\n");
                read(nom,50);
                articles=insert(articles, cle, nom);
                for (int i=0; i<X; i++){
                    printf("Numero de l'article a ajouter:\n");
                    scanf("%d", &cle);
                    cleanBuffer();
                    if(checksearch(articles,cle)){
                        printf("Erreur, cle deja existante\n");
                        break;
                    }
                    printf("Nom de l'article:\n");;
                    read(nom,50);
                    insert(articles, cle, nom);
                }
                break;
            case 2:
                printf("Nom du fichier ?\n");
                read(nomF, 255);
                saisiefichier(articles, nomF);
                break;
            case 3:
                printf("Entrer l'ID a supprimer :\n");
                scanf("%d",&DelCle);
                del(articles, DelCle);
                break;
            case 4:
                printf("Entrer l'ID a rechercher :\n");
                scanf("%d",&SearchCle);
                recherche(articles,SearchCle);
                break;
            case 5:
                affichage(articles);
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