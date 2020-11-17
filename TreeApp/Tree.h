#pragma once
#include "Sommet.h"
#include "mainwindow.h"

class ArbreB {
public:
    static ArbreB* globalTree; // variable statique qui pointe vers l'arbre à afficher
    Sommet* root;
public:
    ArbreB() = delete;
    ArbreB(const Sommet& root); // obligation de créer un objet ArbreB avec un Sommet root prédéfini
    static void GlobalTree(std::string text); // créer la variable globalTree
    ~ArbreB(); // destructeur
    ArbreB & operator = (const ArbreB& t);
    const ArbreB operator+(const ArbreB& t); // addition de deux objet ArbreB et création d'un nouveau Sommet root en fonction des sous-sommets
    void print(MainWindow* w); // print the Tree in GUI
    int search(std::string lookFor)const; // renvoyer la valeur du contenu correspondant (récursif) ou 0 autrement
};
