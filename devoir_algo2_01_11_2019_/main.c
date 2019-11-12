#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
/* DEBUT */
int NCASE = 3;
int i,j;
int tab[NCASE][NCASE];
int x_j1=0;
int y_j1=0;
int x_j2=0;
int y_j2=0;
int k=0;
for (i=0; i<NCASE; i++) {                /*Affichage*/
    for (j=0; j<NCASE; j++) {
        tab[i][j] = 0;
}
}
i=0;
int p=0;
while (k<NCASE){
          printf("     0  1  2\n\n" ); /*Affichage des coordonnées utile pour que le joueurs tappe les coordonées */
for (i=0; i<NCASE; i++) {
if (i<3){
printf("%d%d | ", p, i);
} else {
printf("%d | ", i);}
                                            /*Affichage*/
    for (j=0; j<NCASE; j++) {               /*du*/
        printf("%d |", tab[i][j]);            /*tableau*/
     }
    printf("\n" );
}
              /*Demande des coordonnées au joueur 1*/
    printf("\nJoueur 1, veuillez entrez l'ordonnee :\n" );
    scanf("%d", &x_j1);
    printf("\nJoueur 1, veuillez entrez l'abscisse :\n" );
    scanf("%d", &y_j1);
    tab[x_j1][y_j1] = 1;

    k++;




         /*Demande des coordonnées au joueur 2*/
    printf("\nJoueur 2, veuillez entrez l'ordonnee :\n" );
    scanf("%d", &x_j2);
    printf("\nJoueur 2, veuillez entrez l'abscisse :\n" );
    scanf("%d", &y_j2);
    tab[x_j2][y_j2] = 2;

    k++;
}
  return EXIT_SUCCESS;
}
