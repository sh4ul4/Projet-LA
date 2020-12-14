
# TreeApp

Projet C++ : Cryptage et décryptage avec une Graphical User Interface (GUI)  
Louis-Wilhelm Raban-Schürmann / Arthur Herblot  

## Installation

Un Makefile se trouve à la base du projet.  
Il utilise CMake, un outil de compilation.
```bash
make
```
Après cette étape un dossier Debug/ et un dossier Release/ apparaissent.  
Dans ces dossiers se trouveront les build du projet avec leurs Makefile respectif.
```bash
cd Release
make
```
Ainsi un exécutable est produit.

## Utilisation

```bash
./TreeApp
```
La GUI qui apparaît contient deux entrées pour le clavier en bas de la fenêtre.  
Le texte entré à gauche initie l'affichage de l'arbre correspondant. 
Le texte entré à droite initie l'affichage du code binaire correspondant.
Un descriptif plus détaillé de la GUI ainsi que des photos exemples se trouvent dans [resume_GUI.pdf](/resume_GUI.pdf).

## Documentation

La GUI est faite avec [Qt](https://www.qt.io/).
Une documentation automatique est implémentée grâce à [Doxygen](https://www.doxygen.nl/index.html).  
Bien que la documentation a été pré générée il suffit d'entrer le code suivant à la base du projet pour la regénérer: 
```bash
make documentation
```
La documentation se trouve dans le fichier [doxygen](/doxygen).  