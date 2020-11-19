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
La GUI qui apparaît contient une entrée pour le clavier en bas de la fenêtre.  
Le texte entré est automatiquement afficher sous sa forme d'arbre dans la GUI.

## Documentation

La GUI est faite avec [Qt](https://www.qt.io/).
Une documentation automatique est implémentée grâce à [Doxygen](https://www.doxygen.nl/index.html).  
Pour générer cette Documentation il suffit d'entrer à la base du projet : 
```bash
make documentation
```
La documentation se trouve dans le fichier [doxygen](/doxygen).