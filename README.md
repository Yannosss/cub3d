# cub3D

## Plan
#### 1 - Objectif du projet
#### 2 - Lancement du programme
#### 3 - Fonctionnement du programme

### 1 - Objectif du projet
Cub3D fait partie des projets de l'école 42 et consiste à recréer un mini moteur graphique permettant d'afficher un monde 3D à partir d'une map en 2D et d'un jeu de textures qui seront appliquées sur les murs. L'affichage en 3D est basé sur un algorithme de raycasting.
Ce projet est réalisé en langage C et utilise la minilibX qui est une bibliothèque permettant l'affichage de pixels sur une fenêtre graphique.

### 2 - Lancement du programme
La compilation se fait à l'aide du Makefile avec la commande : 
```
make -j
```

L'exécution se fait en spécifiant le nom de la map à lancer en argument du programme, par exemple :
```
./cub3D ./maps/valid_maps/10_medium_map_sky_texture.cub
```

### 3 - Fonctionnement du programme
#### 3.1 - Lecture et formatage de la map
#### 3.2 - Gestion des textures
#### 3.3 - Initialisation de la MLX
#### 3.4 - Raycasting
#### 3.5 - Gestion des évènements (hooks)
#### 3.6 - Fin du programme

