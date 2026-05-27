# Projet Jeux Puissance 4
Projet réalisé dans le cadre du mini-projet de Programmation Impérative en Licence 1 à l’Université Sorbonne Paris Nord.

## Description

Ce projet consiste en une implémentation du célèbre jeu **Puissance 4** en langage **C**, jouable directement dans la console.

Le jeu oppose deux joueurs qui jouent chacun leur tour en plaçant un pion dans une grille verticale.

Le premier joueur à aligner **4 pions horizontalement, verticalement ou en diagonale** remporte la partie.

## Fonctionnalités

Le programme gère :

- l’affichage dynamique de la grille ;
- la saisie des coups des joueurs ;
- la vérification des conditions de victoire ;
- la détection d’égalité lorsque la grille est remplie.

### Fonctionnalités principales

- Interface en mode texte simple et intuitive
- Jeu à deux joueurs
- Vérification automatique des règles
- Détection des erreurs de saisie
- Organisation du code avec fonctions et structures en C

## Technologies utilisées

- Langage C
- Compilation avec gcc
- Exécution dans le terminal

## Compilation

```bash
gcc main.c -o puissance4
```

## Lancer le jeu

```bash
./puissance4
```
