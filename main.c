#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"sokoban.h"

int main(){
    Grille grille;
    int numNiveau = 1;
    char nomFichier[MAX_SIZE];
    time_t debut;
    time_t fin;
    int nbMouvements=0;
    int nbCaissesBienPlacees=0;
    
    do{
        sprintf(nomFichier, "Niveau-%02d.txt", numNiveau);
        chargerLabyrinthe(&grille, nomFichier);
        rechercherCoordonneesP(&grille);
        time(&debut);
        lancerJeu(&grille);
        time(&fin);
        afficherScore(&grille, debut, fin, nbMouvements, nbCaissesBienPlacees);
        printf("Choisissez votre niveau : ");
        scanf("%d", &numNiveau);
    } while(numNiveau < 11);
    
    return 0;
}
