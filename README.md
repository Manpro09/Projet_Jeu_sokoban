# Projet_Jeu_sokoban


Notre code offre une expérience de jeu pour Sokoban, où le joueur guide le personnage ('P') à travers un labyrinthe, plaçant les caisses ('C') sur les cases d'arrivée ('I'), transformées en 'O'. Une structure de grille stocke les informations, avec des fonctions pour charger le labyrinthe, l'afficher, gérer le déplacement du personnage, et vérifier la fin du jeu. La fonction principale lance une boucle pour charger le labyrinthe, afficher le jeu, permettre au joueur de déplacer le personnage avec des commandes ('h' pour haut, 'b' pour bas, 'g' pour gauche, et 'd' pour droite), et quitter avec 'q'. Des messages avertissent si le déplacement n'est pas possible, et un message de victoire s'affiche si le jeu est gagné. Enfin, le temps et le score sont affichés grâce à time.h et afficherScore.

# Instruction pour commencer le jeu 
Assurer vous d'avoir mis tous les fchiers dans un même repertoire et ensuite , 
- Pour compiler : make  
- Pour exécuter : ./main 
- Pour effacer les exécutables et les fichiers.o make clean
