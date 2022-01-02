#include "ARBRE.h"

int main() {
    struct ARBRE* articles = NULL;
    char nom[50], nomF[255];
    int cle, nb=0, fin=0, SearchCle, DelCle;
    //données inséré à des fins de test
    articles=insert(articles, 1, "as");
    articles=insert(articles, 2, "rf");
    articles=insert(articles, 50, "tg");
    articles=insert(articles, 30, "ik");
    while(!fin){
        switch(menu()){
            case 1:
                printf("Nombre d'articles a saisir ?\n");
                scanf("%d", &nb);
                if(nb<=0){
                    printf("Erreur, nombre d'articles invalide\n");
                    break;
                }
                for (int i=0; i<nb; i++){
                    printf("Numero de l'article a ajouter:\n");
                    scanf("%d", &cle);
                    cleanBuffer();
                    if(checksearch(articles,cle)){
                        printf("Erreur, cle deja existante\n");
                        break;
                    }
                    printf("Nom de l'article:\n");;
                    read(nom,50);
                    printf("%d, %s\n",cle, nom);
                    articles=insert(articles, cle, getNom(nom));
                }
                break;
            case 2:
                printf("La premiere ligne doit comporter le nombre de donnees (cle)\n");
                printf("Les suivantes, le nom de celle-ci suivi de son ID\n");
                printf("Nom du fichier ?\n");
                cleanBuffer();
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
                printf("Affichage dans l'ordre croissant des ID\n");
                affichage(articles);
                break;
            case 6:
                printf("Affichage dans l'ordre decroissant des ID\n");
                affichageinverse(articles);
                break;
            case 7:
                printf("Fermeture du programme\n");
                fin=1;
                break;
            default:
                printf("Erreur de saisie");
                break;
        }
    }
    return 0;
}