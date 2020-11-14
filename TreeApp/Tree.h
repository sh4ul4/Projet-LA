#pragma once
#include "Sommet.h"

class ArbreB {
    Sommet root;
public:
    ArbreB() = delete;
    ArbreB(const Sommet& root); // obligation de créer un objet ArbreB avec un Sommet root prédéfini
    const ArbreB operator+(const ArbreB& t); // addition de deux objet ArbreB et création d'un nouveau Sommet root en fonction des sous-sommets
    void print(MainWindow* w, const int& x, const int& y)const; // print the Tree in GUI
    void print(MainWindow* w)const; // print the Tree in GUI
    int search(std::string lookFor)const; // renvoyer la valeur du contenu correspondant (récursif) ou 0 autrement
};
