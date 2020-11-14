#pragma once
#include <iostream>
#include <string>

#include "mainwindow.h"
#include "line.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class Sommet{
    Sommet* left = nullptr;
    Sommet* right = nullptr;
    std::string letters; // contenu du Sommet
    int value; // valeur du contenu
public:
    Sommet() = delete;
    Sommet(std::string letters, int value);
    Sommet(const Sommet& s); // constructeur de copie
    ~Sommet();
    void setLeft(const Sommet& s); // redéfinir le Sommet gauche par copie
    void setRight(const Sommet& s); // redéfinir le Sommet droit par copie
    int getValue()const;
    std::string getLetters()const;
    Sommet operator+(const Sommet& s)const; // addition de deux objets Sommet (copie récursive des feuilles) en un nouveau objet Sommet
private:
    void clickedSlot()const; // réaction au clic d'un objet QPushButton
public:
    void print(MainWindow* w, const int& x, const int& y, const int& index) const; // afficher le Sommet en GUI (récursif)
    int search(const std::string lookFor)const; // renvoyer la valeur du contenu correspondant (récursif)
};
