#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "sokoban.h"
#define MAX_SIZE 500

// Définition de la structure de la grille
//typedef struct {
//    char grille[MAX_SIZE][MAX_SIZE];
//    int nbLignes;
//    int nbColonnes;
//    int posX;
//    int posY;
//}Grille;

void rechercherCoordonneesP(Grille *grille) {
	int i,j;
    for(i = 0; i < grille->nbLignes; i++) {
        for(j = 0; j < grille->nbColonnes; j++) {
            if(grille->grille[i][j] == 'P') {
                grille->posX = i;
                grille->posY = j;
            }
        }
    }
}
// Fonction qui permet de récupérer la taille du labyrinthe à partir du fichier
void recupererTaille(Grille *grille, char *fichier) {
    FILE *f = fopen(fichier, "r");
    if(f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int nbLignes = 0;
    int nbColonnes = 0;

    // Lecture et comptage des lignes et colonnes
    char ligne[MAX_SIZE];
    while(fgets(ligne, MAX_SIZE, f) != NULL) {
        int l = strlen(ligne);
        if(l > nbColonnes) {
            nbColonnes = l;
        }
        nbLignes++;
    }

    fclose(f);

    grille->nbLignes = nbLignes;
    grille->nbColonnes = nbColonnes;
}
// Fonction qui permet de charger le labyrinthe à partir d'un fichier texte
void chargerLabyrinthe(Grille *grille, char *fichier) {
    recupererTaille(grille, fichier);

    FILE *f = fopen(fichier, "r");
    if(f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Lecture et remplissage de la grille
    char ligne[MAX_SIZE];
    int i = 0;
    while(fgets(ligne, MAX_SIZE, f) != NULL) {
        int j;
        for(j = 0; j < grille->nbColonnes; j++) {
            if (j < strlen(ligne)) {
                grille->grille[i][j] = ligne[j];
            } else {
                grille->grille[i][j] = ' ';
            }
        }
        i++;
    }

    fclose(f);
  }
// Fonction qui permet d'afficher le labyrinthe

void afficherLabyrinthe(Grille *grille) {
    int i, j;
    for(i = 0; i < grille->nbLignes; i++) {
        for(j = 0; j < grille->nbColonnes; j++) {
            if(i == 0) {
                printf("%c", grille->grille[i][j]);
            } 
			else
			{
				if(grille->grille[i][j] == ' ')
				{
					printf("  ");
				}
				else
				{
					printf(" %c", grille->grille[i][j]);
				}
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Fonction qui permet de déplacer le personnage
void deplacerPersonnage(Grille *grille, char direction) {
    int nouvellePosX = grille->posX;
    int nouvellePosY = grille->posY;

    // Calcul de la nouvelle position
    switch(direction) {
        case 'h': // Haut
            nouvellePosX--;
            break;
        case 'b': // Bas
            nouvellePosX++;
            break;
        case 'g': // Gauche
            nouvellePosY--;
            break;
        case 'd': // Droite
            nouvellePosY++;
            break;
    }

    // Vérification des limites
    if(nouvellePosX < 0 || nouvellePosX >= grille->nbLignes ||
        nouvellePosY < 0 || nouvellePosY >= grille->nbColonnes) {
        printf("Mouvement impossible\n");
        return;
    }

    // Vérification de la présence d'un mur
    if(grille->grille[nouvellePosX][nouvellePosY] == '#') {
        printf("Mouvement impossible\n");
        return;
    }

    // Vérification de la présence d'une caisse
    if(grille->grille[nouvellePosX][nouvellePosY] == 'C') {
        // Calcul de la position de la caisse
        int caisseX = nouvellePosX;
        int caisseY = nouvellePosY;
        switch (direction) {
            case 'h': // Haut
                caisseX--;
                break;
            case 'b': // Bas
                caisseX++;
                break;
            case 'g': // Gauche
                caisseY--;
                break;
            case 'd': // Droite
                caisseY++;
                break;
        }

        // Vérification des limites
        if(caisseX < 0 || caisseX >= grille->nbLignes ||
            caisseY < 0 || caisseY >= grille->nbColonnes) {
            printf("Mouvement impossible\n");
            return;
        }

        // Vérification de la présence d'un mur
        if(grille->grille[caisseX][caisseY] == '#') {
            printf("Mouvement impossible\n");
            return;
        }

        // Vérification de la présence d'une autre caisse
        if(grille->grille[caisseX][caisseY] == 'C') {
            printf("Mouvement impossible\n");
            return;
        }

        // Vérification de la présence d'une case d'arrivée
        if(grille->grille[caisseX][caisseY] == 'I') {
            grille->grille[caisseX][caisseY] = 'O';
        } 
		else if (grille->grille[caisseX][caisseY] == 'O') {
            grille->grille[caisseX][caisseY] = 'C';
            grille->grille[nouvellePosX][nouvellePosY] = 'O';
        }
		else {
            grille->grille[caisseX][caisseY] = 'C';
        }
    }

    // Déplacement du personnage
    grille->grille[grille->posX][grille->posY] = ' ';
    grille->grille[nouvellePosX][nouvellePosY] = 'P';
    grille->posX = nouvellePosX;
    grille->posY = nouvellePosY;
}
// Fonction qui permet de vérifier si le jeu est gagné
int verifierGagne(Grille *grille) {
    int i, j;
    for(i = 0; i < grille->nbLignes; i++) {
        for(j = 0; j < grille->nbColonnes; j++) {
            if(grille->grille[i][j] == 'C' && grille->grille[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
	if (grille->grille[i][j] != 'C')
	{
		return 1;
	}
}

void lancerJeu(Grille *grille){
	int true=1;
	int false=0;
        afficherLabyrinthe(grille);
        char direction;
	time_t debut;
	time_t fin;
	time(&debut);
    do{
        printf("Direction (h/b/g/d/q) ? ");
        scanf(" %c", &direction);
        deplacerPersonnage(grille, direction);
        afficherLabyrinthe(grille);
        if(verifierGagne(grille)==1)
        {
        	printf("Bravo ,vous avez gagné \n");
        	
		}
		printf("Appuyez q pour quitter ce niveau \n");
	if(direction =='e')
	{
	        exit(0);
	        }
	
    } while(direction != 'q');
	time(&fin);
	
    printf("Votre temps est de %ld secondes\n",fin-debut);
    
    if(verifierGagne(grille)==0) {
        printf("Vous n'avez pas réussie , essayez encore \n");

    }
    printf(" Maintenant a quel niveau voulez-vous jouer? : ");
    printf("le choix du niveau se fait de 1 a 10 \n");

}
// Fonction qui permet d'afficher le score
void afficherScore(Grille *grille, time_t debut, time_t fin, int nbMouvements, int nbCaissesBienPlacees) {
    int score = 0;
    int nbSecondes = fin - debut;
    int nbCaisses = 0;
    int i, j;
    for(i = 0; i < grille->nbLignes; i++) {
        for(j = 0; j < grille->nbColonnes; j++) {
            if(grille->grille[i][j] == 'C' || grille->grille[i][j] == 'O') {
                nbCaisses++;
            }
        }
    }
    score = (nbSecondes + nbMouvements) * (nbCaisses - nbCaissesBienPlacees);
    printf(" Voila votre score pour le niveau précédent est de %d\n", score);
}


