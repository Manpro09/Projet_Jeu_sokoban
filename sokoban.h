#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_SIZE 500
// definition de la structure de la grille

typedef struct
{ 
char grille[MAX_SIZE][MAX_SIZE];
int nbLignes;
int nbColonnes;
int posX;
int posY;
}Grille;


time_t debut;
time_t fin;
//int nbMouvements=0;
//int nbCaissesBienPlacees=0;


void rechercherCoordonneesP(Grille *grille);
void recupererTaille(Grille *grille, char *fichier);
void chargerLabyrinthe(Grille *grille, char *fichier);
void afficherLabyrinthe(Grille *grille);
void deplacerPersonnage(Grille *grille, char direction);
int verifierGagne(Grille *grille);
void lancerJeu(Grille *grille);
void afficherScore(Grille *grille, time_t debut, time_t fin, int nbMouvements, int nbCaissesBienPlacees);
