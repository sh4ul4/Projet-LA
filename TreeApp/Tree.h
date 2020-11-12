#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

class Sommet {
    Sommet* left = nullptr;
    Sommet* right = nullptr;
    std::string letters;
    int value;
public:
    Sommet() = delete;
    Sommet(std::string letters, int value) : letters(letters), value(value) {}
    Sommet(const Sommet& s) { // copy constructor
        if (s.left != nullptr) left = new Sommet(*s.left);
        if (s.right != nullptr) right = new Sommet(*s.right);
        value = s.value;
        letters = s.letters;
    }
    ~Sommet() { // free memory in destructor
        delete left;
        delete right;
    }
    void setLeft(const Sommet& s) {
        if(left != nullptr)delete left;
        Sommet* newS = new Sommet(s);
        left = newS;
    }
    void setRight(const Sommet& s) {
        if(right != nullptr)delete right;
        Sommet* newS = new Sommet(s);
        right = newS;
    }
    int getValue()const { return value; }
    std::string getLetters()const { return letters; }
    Sommet operator+(const Sommet& s)const  {
        if (search(s.letters) > 0) { // error case
            std::cout << "letters already exist in subSommet" << std::endl;
            exit(1);
        }
        if (this->value < s.getValue()) { // greater value is always in left
            Sommet res(this->letters + s.getLetters(), this->value + s.getValue());
            res.setLeft(*this);
            res.setRight(s);
            return res;
        }
        else {
            Sommet res(s.getLetters() + this->letters, this->value + s.getValue());
            res.setLeft(s);
            res.setRight(*this);
            return res;
        }
    }
    void print(MainWindow* w, int x, int y) const {
        QLabel* label = new QLabel(w);
        label->setText(letters.c_str());
        label->setGeometry(x,y,7 * letters.length() + 7,15);
        label->setStyleSheet("border: 1px solid black");
        //std::cout << letters << " " << value << std::endl;
        y+=20;
        if (left != nullptr)left->print(w,x,y);

        if (right != nullptr){
            x+=10 + 10 * left->letters.length();
            right->print(w,x,y);
        }

    }
    int search(std::string lookFor)const {
        int res = 0;
        if (letters == lookFor) res = value;
        if (left != nullptr) res += left->search(lookFor);
        if (right != nullptr) res += right->search(lookFor);
        return res;
    }
};

class ArbreB {
    Sommet root;
public:
    ArbreB() = delete;
    ArbreB(const Sommet& root) :root(root) {}
    const ArbreB operator+(const ArbreB& t) {
        ArbreB res(root + t.root);
        return res;
    }
    void print(MainWindow* w, const int& x, const int& y)const {
        root.print(w,x,y-20);
    }
    int search(std::string lookFor)const { // returns value of given letters or 0 if not found
        return root.search(lookFor);
    }
};
