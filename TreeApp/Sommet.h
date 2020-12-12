#pragma once
#include <iostream>
#include <string>

#include "line.h"
#include "panel.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class Sommet{
public:
    Sommet* left = nullptr;
    Sommet* right = nullptr;
private:
    std::string letters; // contenu du Sommet
    int value; // valeur du contenu
    // partie graphique
    std::vector<Line*> lines; // contient les lignes
    QLabel* label = nullptr; // sert à afficher la valeur
    QPushButton* b = nullptr; // sert à afficher les lettres
public:
    static int Buttonind;
    Sommet() = delete;
    Sommet(std::string letters, int value);// constructeur basique
    Sommet(const Sommet& s); // constructeur par copie
    ~Sommet();
    void setValue(const int& val);
    void setLeft(const Sommet& s); // redéfinir le Sommet gauche par copie
    void setRight(const Sommet& s); // redéfinir le Sommet droit par copie
    int getValue()const;
    std::string getLetters()const;
    Sommet operator+(const Sommet& s)const; // addition de deux objets Sommet (copie récursive des feuilles) en un nouveau objet Sommet
    bool operator<(const Sommet& s)const; // compare two objects Sommet
    bool operator>(const Sommet& s)const; // compare two objects Sommet
    Sommet& operator=(const Sommet& other); // copie
private:
    void clickedSlot(Panel* panel, const int& x, const int& y); // réaction au clic d'un objet QPushButton
    void printValues(Panel* panel, const int& x, const int& y); // afficher le Sommet en GUI (récursif)
    void printLines(Panel* panel); // affichage complet récursif
public:
    void print(Panel* panel, const int& x, const int& y);
    int search(const std::string lookFor)const; // renvoyer la valeur du contenu correspondant (récursif)
    std::string getBinary(const char c)const; // renvoyer le string binaire d'un caractère du sommet (récursif)
};
