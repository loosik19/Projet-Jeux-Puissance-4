/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf  scanf */

/* declaration constantes et types utilisateurs */
#define longueur 7  /*Longueur du jeu (colonnes)*/
#define largeur 5 /*Largeur du jeu (lignes)*/

struct a_s  /*Structure qui contient tout les variables utilisées dans les différentes fonctions*/
{
  char J1c; /*Couleur joueur 1*/
  char J2c; /*Couleur joueur 2*/
  int la, lo; /*Variable pour parcourir la matrice*/
  char tab[largeur][longueur]; /*La matrice de largeur 5 et de longueur 7*/
  int jp; /*Variable pour la position entré par le joueur*/
  int pos_avant;  /*Variable pour avoir la position d'une colonne*/
  int pos1, pos2, pos3, pos4, pos5, pos6, pos7; /*Chaque variable correspond à chaque colonne*/
  int all;  /*Variable qui permet de vérifier si gagné ou perdu ou match nul*/
  int play1;  /*Variable qui permet alterner entre les deux joueurs*/
};


/* declaration de fonctions utilisateurs */
struct a_s couleur();  /*Choix des couleurs*/
void affichage(struct a_s res); /*Première affichage du jeu pour avoir une vision du jeu*/
void play1(struct a_s res); /*Jeu du joueur 1 et affichage après son jeu*/
void play2(struct a_s res); /*Jeu du joueur 2 et affichage après son jeu*/
void Verification(struct a_s res);  /*Vérification si gagnant/partie nul/perdant et si le jeu continu passage au joueur suivant*/

/* fonction principale */
int main()
{
  /* declaration et initialisation des variables */
  struct a_s res=couleur(); /*Choix des couleurs*/
  res.pos1=4; /*Variable initialisé à la position du premier jeton dans la colonne 1*/
  res.pos2=4; /*Variable initialisé à la position du premier jeton dans la colonne 2*/
  res.pos3=4; /*Variable initialisé à la position du premier jeton dans la colonne 3*/
  res.pos4=4; /*Variable initialisé à la position du premier jeton dans la colonne 4*/
  res.pos5=4; /*Variable initialisé à la position du premier jeton dans la colonne 5*/
  res.pos6=4; /*Variable initialisé à la position du premier jeton dans la colonne 6*/
  res.pos7=4; /*Variable initialisé à la position du premier jeton dans la colonne 7*/
  affichage(res); /*Affichage de la grille du jeu vide*/
  play1(res); /*Joueur 1 commence le jeu*/
  return EXIT_SUCCESS;
 }

/* definitions des fonctions utilisateurs */
struct a_s couleur()  /*Choix des couleurs*/
{
  struct a_s res;
  printf("Joueur 1 : Choisir votre couleur : J (JAUNE) ou R (ROUGE)\n");  /*Demande au joueur 1  la couleur qu'il souhait*/
  scanf(" %c",&res.J1c);  /*Stocke le choix du joueur 1 dans res.J1c*/
  while ((res.J1c != 'J')&&(res.J1c!='j')&&(res.J1c != 'R')&&(res.J1c!='r'))
  {
    printf("Choix incorrecte\n");
    return couleur();
  }
  if (res.J1c == 'J'||res.J1c=='j') /*Accorde au joueur leur couleur*/
  {
      res.J2c ='R';
      res.J1c ='J';
      printf("Joueur 1 : %c , Joueur 2 : %c\n",res.J1c,res.J2c);/*Affiche la couleur de chacun des joueurs*/
    }
    if (res.J1c == 'R'||res.J1c=='r') /*Accorde au joueur leur couleur*/
    {
      res.J2c ='J';
      res.J1c ='R';
      printf("Joueur 1 : %c , Joueur 2 : %c\n",res.J1c,res.J2c); /*Affiche la couleur de chacun des joueurs*/
    }
  return res;
}

void affichage(struct a_s res)  /*Première affichage du jeu pour avoir une vision du jeu*/
{
  for(res.la=0;res.la<largeur;res.la++) /*Parcours la largeur(lignes)*/
  {
    for(res.lo=0;res.lo<longueur;res.lo++)  /*Parcours la longueur(colonne) en fonction de la largeur*/
    {
      res.tab[res.la][res.lo]='_';  /*Chaque intersection ligne et colonne correspond à '_' pour montrer qu'on peut y mettre un jetons*/
      printf(" %c",res.tab[res.la][res.lo]);  /*Affichage de chaque intersection*/
    }
    printf("\n"); /*Retour à la ligne*/
  }
  /*Numérotation des colonnes du plateau*/
  int a=1;  /*Variable initialisé à 1 car la première colonne est 1*/
  while (a<=longueur) /*Tant que la variable i n'est pas égale à longueur(7)*/
  {
    printf(" %d",a);  /*Affichage de la variable i qui correspond au numéro de colonne*/
    a++;  /*Incrémentation de la variable*/
  }
  printf("\n");  /*Retour à la ligne*/
}

void play1(struct a_s res)  /*Jeu du joueur 1 et affichage après son jeu*/
{
  printf("Joueur 1 : Entrez la colonne ou vous voulez entrer votre jetons");  /*Demande la colonne où le joueur 1 veut jouer son jeton*/
  scanf("%d",&res.jp);  /*Stocke dans la variable res.jp la colonne dans lequel le joueur joue son jeton*/
  if (res.jp>7) /*Vérifie si la colonne entrer par le joueur 1 n'est pas hors de limite*/
  {
    printf("Choix incorrecte\n"); /*Si hors de limite affiche choix incorrecte*/
    play1(res); /*Rappel de la fonction play1 pour que le joueur 1 donne un choix correcte*/
  }
  if (res.jp==1)  /*Si la position entrer par le joueur 1 correspond à 1*/
  {
    res.pos_avant=res.pos1; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos1--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 1 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos1<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==2)  /*Si la position entrer par le joueur 1 correspond à 2*/
  {
    res.pos_avant=res.pos2; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos2--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 2 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos2<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==3)  /*Si la position entrer par le joueur 1 correspond à 3*/
  {
    res.pos_avant=res.pos3; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos3--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 3 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos3<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==4)  /*Si la position entrer par le joueur 1 correspond à 4*/
  {
    res.pos_avant=res.pos4; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos4--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 4 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos4<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==5)  /*Si la position entrer par le joueur 1 correspond à 5*/
  {
    res.pos_avant=res.pos5; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos5--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 5 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos5<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==6)  /*Si la position entrer par le joueur 1 correspond à 6*/
  {
    res.pos_avant=res.pos6; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos6--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 6 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos6<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==7)  /*Si la position entrer par le joueur 1 correspond à 7*/
  {
    res.pos_avant=res.pos7; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos7--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 7 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos7<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 1 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if ((res.tab[largeur-1][res.jp-1]==res.J1c)||(res.tab[largeur-1][res.jp-1]==res.J2c)) 
  {  
    res.tab[res.pos_avant][res.jp-1]=res.J1c;
  }
  else
  {
    res.tab[largeur-1][res.jp-1]=res.J1c;
  }
  for(res.la=0;res.la<largeur;res.la++)  /*Parcours la matrice et si à la position [res.la][res.lo] elle vaut res.J1c ou res.J2c elle affiche l'élément présent à cette postion sinon '_'*/
  {
    for(res.lo=0;res.lo<longueur;res.lo++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)||(res.tab[res.la][res.lo]==res.J2c))
      {
        printf(" %c",res.tab[res.la][res.lo]);
      }
      else
      {
        res.tab[res.la][res.lo]='_';
        printf(" %c",res.tab[res.la][res.lo]);
      }
    }
    printf("\n"); /*Retour à la ligne*/
  }
  /*Numérotation des colonnes du plateau*/
  int a=1;  /*Variable initialisé à 1 car la première colonne est 1*/
  while (a<=longueur) /*Tant que la variable i n'est pas égale à longueur(7)*/
  {
    printf(" %d",a);  /*Affichage de la variable i qui correspond au numéro de colonne*/
    a++;  /*Incrémentation de la variable*/
  }
  printf("\n");  /*Retour à la ligne*/
  res.play1=1;  /*Variable res.play1 vaut 1 pour que joueur 2 puisse jouer*/
  Verification(res);

}
void play2(struct a_s res)  /*Jeu du joueur 2 et affichage après son jeu*/
{
  printf("Joueur 2 : Entrez la colonne ou vous voulez entrer votre jetons");  /*Demande la colonne où le joueur 2 veut jouer son jeton*/
  scanf("%d",&res.jp);  /*Stocke dans la variable res.jp la colonne dans lequel le joueur joue son jeton*/
  if (res.jp>7) /*Vérifie si la colonne entrer par le joueur 2 n'est pas hors de limite*/
  {
    printf("Choix incorrecte\n"); /*Si hors de limite affiche choix incorrecte*/
    play1(res); /*Rappel de la fonction play1 pour que le joueur 2 donne un choix correcte*/
  }
  if (res.jp==1)  /*Si la position entrer par le joueur 2 correspond à 1*/
  {
    res.pos_avant=res.pos1; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos1--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 1 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos1<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==2)  /*Si la position entrer par le joueur 2 correspond à 2*/
  {
    res.pos_avant=res.pos2; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos2--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 2 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos2<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==3)  /*Si la position entrer par le joueur 2 correspond à 3*/
  {
    res.pos_avant=res.pos3; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos3--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 3 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos3<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==4)  /*Si la position entrer par le joueur 2 correspond à 4*/
  {
    res.pos_avant=res.pos4; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos4--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 4 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos4<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==5)  /*Si la position entrer par le joueur 2 correspond à 5*/
  {
    res.pos_avant=res.pos5; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos5--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 5 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos5<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==6)  /*Si la position entrer par le joueur 2 correspond à 6*/
  {
    res.pos_avant=res.pos6; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos6--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 6 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos6<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if (res.jp==7)  /*Si la position entrer par le joueur 2 correspond à 7*/
  {
    res.pos_avant=res.pos7; /*Stocke dans res.pos_avant la positon du dernier jeton jouer dans cette colonne*/
    res.pos7--; /*Décrémente la dernière position du dernier jetons jouer dans la colonne 7 pour pouvoir jouer sur la ligne au dessus*/
    if (res.pos7<-1)  /*Vérifie si la colonne est remplie*/
    {
      printf("Colonne remplit, veuillez entrer dans une autre colonne\n");  /*Affiche colonne remplit et demande d'entrer dans une nouvelle colonne*/
      play1(res); /*Rappel de la fonction play1 pour que le joueur 2 puisse entrer dans une autre colonne non remplit*/
    }
  }
  if ((res.tab[largeur-1][res.jp-1]==res.J1c)||(res.tab[largeur-1][res.jp-1]==res.J2c))
  { 
    res.tab[res.pos_avant][res.jp-1]=res.J2c;
  }
  else
  {
    res.tab[largeur-1][res.jp-1]=res.J2c;
  }
  for(res.la=0;res.la<largeur;res.la++) /*Parcours la matrice et si à la position [res.la][res.lo] elle vaut res.J1c ou res.J2c elle affiche l'élément présent à cette postion sinon '_'*/
  {
    for(res.lo=0;res.lo<longueur;res.lo++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)||(res.tab[res.la][res.lo]==res.J2c))
      {
        printf(" %c",res.tab[res.la][res.lo]);
      }
      else
      {
        res.tab[res.la][res.lo]='_';
        printf(" %c",res.tab[res.la][res.lo]);
      }
    }
    printf("\n"); /*Retour à la ligne*/
  }
  /*Numérotation des colonnes du plateau*/
  int a=1;  /*Variable initialisé à 1 car la première colonne est 1*/
  while (a<=longueur) /*Tant que la variable i n'est pas égale à longueur(7)*/
  {
    printf(" %d",a);  /*Affichage de la variable i qui correspond au numéro de colonne*/
    a++;  /*Incrémentation de la variable*/
  }
  printf("\n");  /*Retour à la ligne*/
  res.play1=0;  /*Variable res.play1 vaut 0 pour que joueur 1 puisse jouer*/
  Verification(res);  /*Appel de la fonction Verification pour vérifier si gagnant/partie nul/perdant*/
}

void Verification(struct a_s res)  /*Vérification si gagnant/partie nul/perdant et si le jeu continu passage au joueur suivant*/
{
  /*Parcours la matrice et vérifie en horizontale s'il y a un gagnant*/
  res.all=0;
  for(res.la=0;res.la<largeur;res.la++) 
  {
    for(res.lo=0;res.lo<longueur-3;res.lo++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+3])) 
      {
        res.all=1;
      }
      if ((res.tab[res.la][res.lo]==res.J2c)&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la][res.lo+3])) 
      {
        res.all=2;
      }
    }
  }
  
  /*Parcours la matrice et vérifie en verticale s'il y a un gagnant*/
  for(res.lo=0;res.lo<longueur;res.lo++)
  {
    for(res.la=0;res.la<largeur-3;res.la++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)&&(res.tab[res.la][res.lo]==res.tab[res.la+1][res.lo])&&(res.tab[res.la][res.lo]==res.tab[res.la+2][res.lo])&&(res.tab[res.la][res.lo]==res.tab[res.la+3][res.lo]))
      {
        res.all=1;
      }
      if ((res.tab[res.la][res.lo]==res.J2c)&&(res.tab[res.la][res.lo]==res.tab[res.la+1][res.lo])&&(res.tab[res.la][res.lo]==res.tab[res.la+2][res.lo])&&(res.tab[res.la][res.lo]==res.tab[res.la+3][res.lo]))
      {
        res.all=2;
      }
    }
  }
  
  /*Parcours la matrice et vérifie en diagonale de haut-gauche à bas-droit s'il y a un gagnant*/
  for(res.la=0;res.la<largeur;res.la++)
  {
    for(res.lo=0;res.lo<longueur-3;res.lo++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)&&(res.tab[res.la][res.lo]==res.tab[res.la-1][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la-2][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la-3][res.lo+3])) 
      {
        res.all=1;
      }
      if ((res.tab[res.la][res.lo]==res.J2c)&&(res.tab[res.la][res.lo]==res.tab[res.la-1][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la-2][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la-3][res.lo+3])) 
      {
        res.all=2;
      }
    }
  }
  
    /*Parcours la matrice et vérifie en diagonale de bas-gauche à haut-droit s'il y a un gagnant*/
  for(res.la=0;res.la<largeur;res.la++)
  {
    for(res.lo=0;res.lo<longueur;res.lo++)
    {
      if ((res.tab[res.la][res.lo]==res.J1c)&&(res.tab[res.la][res.lo]==res.tab[res.la+1][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la+2][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la+3][res.lo+3])) 
      {
        res.all=1;
      }
      if ((res.tab[res.la][res.lo]==res.J2c)&&(res.tab[res.la][res.lo]==res.tab[res.la+1][res.lo+1])&&(res.tab[res.la][res.lo]==res.tab[res.la+2][res.lo+2])&&(res.tab[res.la][res.lo]==res.tab[res.la+3][res.lo+3])) 
      {
        res.all=2;
      }
    }
  }
  int a=0;
  for(res.lo=0;res.lo<longueur;res.lo++)
  {
    if(res.tab[0][res.lo]!='_')
    {
      a++;
    }
  }
  if (a==7)
  {
    res.all=3;
  }
  if (res.all==0) /*Si res.all vaut 0 alors le jeu continue*/
  {
    if (res.play1==1) /*si res.play1 vaut 1 c'est au tour du joueur 2*/
    { 
      play2(res);
    }
    else  /*sinon c'est au tour du joueur 2*/
    { 
      play1(res);
    }
  }
  while (res.all==1) /* Si res.all vaut 1 alors le joueur 1 a gagné*/
  {
    printf("Joueur 1: Vous avez gagné\n");
    printf("Joueur 2: Vous avez perdu\n");
    break;
  }
  while (res.all==2) /*Si res.all vaut 2 alors le joueur 2 a gagné*/
  {
    printf("Joueur 2: Vous avez gagné\n");
    printf("Joueur 1: Vous avez perdu\n");
    break;
  }
  while (res.all==3)
    {
      printf("March nul\n");
      break;
    }
}

