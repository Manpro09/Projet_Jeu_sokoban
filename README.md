# Projet_Jeu_sokoban

Notre code permet de jouer au jeu de Sokoban, où l’objectif est de déplacer
un personnage représenté par un ’P’ à travers un labyrinthe et de placer toutes
les caisses représentées par des ’C’ sur les cases d’arrivées représentées par des
’I’,quand cela se produit la position est changé par un ’O’. .Nous avons définit une
structure de grille qui stocke les informations sur le labyrinthe et des fonctions
pour le déroulement du jeu, comme le chargement du labyrinthe à partir
d’un fichier, l’affichage du labyrinthe, le déplacement du personnage et
la vérification de la fin du jeu.
Pour lancer le jeu, nous avons écrit une fonction principale qui initialise les variables nécessaires, puis démarre une boucle qui charge
le labyrinthe à partir du fichier contenant les différents labyrinthe, affiche le labyrinthe et demande à l’utilisateur de choisir une direction (’h’ pour haut, ’b’
pour bas, ’g’ pour gauche ,’d’ pour droite) pour déplacer le personnage et
pour quitter le jeu appuyer sur la touche ’q’.

Pour compiler : Make 
-Pour exécuter : ./main 
-Pour effacer les exécutables et les fichiers.o make clean
