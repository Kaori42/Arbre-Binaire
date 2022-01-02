#ifndef MAIN_C_ARBRE_H
#define MAIN_C_ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Définition de la structure ARBRE
struct ARBRE {
    int cle;
    char nom[50];
    struct ARBRE *gauche, *droite;
};

//Méthode de création d'un Noeud
struct ARBRE* creerNoeud(int cle, char *nom);

//Insertion de valeurs
struct ARBRE* insert(struct ARBRE* a, int cle, char *nom);
//Insertion de valeurs à partir d'un fichier
struct ARBRE* saisiefichier(struct ARBRE* a, char *fichier);
//Permet de trouver la cle la plus petite d'un arbre
struct ARBRE* min(struct ARBRE* a);
//Supprime une clé
struct ARBRE* del(struct ARBRE* a, int cle);
//Recherche une clé
void recherche(struct ARBRE* a, int cle);
//Recherche mais pour vérifier que la clé n'existe pas déjà
int checksearch(struct ARBRE* a, int cle);
//Affichage de l'arbre dans l'ordre croissant
void affichage(struct ARBRE* a);
//Affichage de l'arbre dans l'ordre décroissant
void affichageinverse(struct ARBRE* a);

//Permet de nettoyer le buffer pour les fonctions de lecture
void cleanBuffer();
//Lecture de string sans \n
int read(char *string, int lengh);

char* getNom(char *nom);

//Affichage du menu
int menu();

#endif