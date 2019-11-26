#include <stdio.h> // Fonctions getchar, printf()
#include <stdlib.h> // Fonctions system
#include <string.h>
#include <time.h>
#define OK 1

void jeu();

void initCode(char *codeSecret);
void analyserCombinaison(char *comb, char *rep, char *resultat);
int main ()
{
int continuer = 1, choix = 0;
while (continuer)
{
    jeu();
}
return 0;
}

    void verifierCombi(char *comb, char *rep, char *resultat) // test la combinaison entrée par le joueur pour voir si elle est possible.
    {
    char repMinuscule[4];
    int a;
    for(a=0;a<4;a++)
    {
     repMinuscule[a]=tolower(rep[a]); //Permet de transformer une majuscule en minuscule, ce qui permettra d'enter à la fois des minuscules et des majuscules comme combinaison
     }

    int controle[4] = {0,0,0,0};//verifie qu'il ni a pas de N sur une position
    int j=0;
    int i;
         for( i = 0;i<4;i++)//detect les point noir
         {
             if (repMinuscule[i]==comb[i])
             {
              resultat[j] = 'N';
              j++;
              controle[i] = OK;
             }
         }

         for(i = 0;i<4;i++)//Sert à détecter les pions blancs
         {
                 if(controle[i]!=OK)
                 {
                       int k;
                       for(k=0;k<4;k++)
                       {
                               if (repMinuscule[k]==comb[i] && controle[i]!=OK)
                               {
                                resultat[j]= 'B';
                                j++;
                                controle[i] = OK;
                               }

                       }
                 }
         }
    }
void initCode(char *codeSecret) //Fonction qui genere les code avec la list de chiffre proposer
{


int i;
srand (time(NULL));
/* créent le code secret*/
for (i = 0; i < 4 ; i++)
{
 switch (rand() % 6)
 {
  case 0: codeSecret[i] = '1'; break;
  case 1: codeSecret[i] = '2'; break;
  case 2: codeSecret[i] = '3'; break;
  case 3: codeSecret[i] = '4'; break;
  case 4: codeSecret[i] = '5'; break;
  case 5: codeSecret[i] = '6'; break;
 }
}
}

    void jeu()
    {
        int essais=0,choix=0, ligne=9,continuer=1,verif=0,a; // tableau
        char tab[12][8]={
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46}
                        };
        char comb[5];
        initCode(comb);
                system("cls" );

            // Jeu du MASTERMIND
            char rep[5]={'\0'};
            while (essais <= 12)
            {
                char resultat[4]={46,46,46,46};
                int i, j, t, test=0, L=1, verif=0; // L : numéroter la ligne du tableau à partir de 10. ligne -> monter d'une ligne lorsque l'on entre une combinaison

                int a,b; // variable pour la vérification des combinaisons entrées
                system("cls" ); // Nettoyer la console
                printf("\n chiffre disponibles : \n" );
                printf("1 - 2 - 3 - 4 - 5 - 6  \n" );
                // affichage du tableau
                for (i=0;i<=9;i++)
                {
                    printf ("[%3d]-[",L);
                    for (j=0;j<=7;j++)
                    {
                        printf ("(%c)",tab[i][j]);
                    }
                    printf (" ]\n" );
                    L++;
                }


                // Entrer une combinaison
                while (verif != 4)
                {
                    verif=0;
                    printf("\n\nEssai n# %d: \n",essais);
                    scanf("%s",&rep);
                    fflush(stdin);
                    // vérification de la combinaison entrée
                    for (a=0;a<=3;a++)
                    {
                        if (rep[a]=='1' || rep[a]=='2' || rep[a]=='3' || rep[a]=='4' || rep[a]=='5' || rep[a]=='6' )
                        {
                            verif++;
                        }
                        else
                        {
                            verif--;
                        }
                    }
                    if (verif !=4)
                    {
                        printf("\nCombinaison impossible. Recommencez !" );
                    }
                }


                verifierCombi(comb,rep,resultat);


                tab[essais][0]=rep[0];
                tab[essais][1]=rep[1];
                tab[essais][2]=rep[2];
                tab[essais][3]=rep[3];
                tab[essais][4]=resultat[0];
                tab[essais][5]=resultat[1];
                tab[essais][6]=resultat[2];
                tab[essais][7]=resultat[3];

              if (resultat[0]=='N' && resultat[1]=='N' && resultat[2]=='N' && resultat[3]=='N')// Si 4 'N' alors le joueur a trouvé le code secret
                {
                   essais=99;
                                     }
                else{
                     essais++;
                }
    }



            // Jeu terminé
            if (essais == 99) // si essais == 99, alors le joueurs a trouvé la combinaison
            {
                printf("Jeu termine" );
                printf("\n\n  B R A V O \n" );
                printf("\n VOUS AVEZ TROUVE LA COMBINAISON \n" );


            }
            else
            {
                system("cls" ); // Nettoyer la console
                printf("Jeu termine" );


            }


}
