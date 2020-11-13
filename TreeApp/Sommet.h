#pragma once

#include <iostream>
#include <string>

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPainter>

class Line : public QWidget
{
    int ax,ay,bx,by;
public:
    explicit Line(QWidget* parent=nullptr):QWidget(parent){}
    void set(int ax,int ay,int bx,int by){
        this->ax = ax;
        this->ay = ay;
        this->bx = bx;
        this->by = by;
    }
protected:
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);
        QPainter painter(this);
        this->setGeometry(0,0,900,900);
        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        painter.drawLine(ax, ay, bx, by);
    }
};

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
    void print(MainWindow* w, int x, int y, int index) const {
        QLabel* label = new QLabel(w);
        label->setText(letters.c_str());
        label->setGeometry(x,y,7 * letters.length() + 7,15);
        label->setStyleSheet("border: 1px solid black");
        //std::cout << letters << " " << value << std::endl;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if (left != nullptr) left->print(w,x - y / (index + 1), y + 50,leftIndex);
        if (right != nullptr) right->print(w,x + y / (index + 1), y + 50,rightIndex);
        // left line
        if(left != nullptr) {
            Line* line = new Line(w);
            line->set(x + (7 * letters.length() + 7)/2, y + 15, x - y / (index + 1)+ (7 * letters.length() + 7)/2, y + 50);
        } // right line
        if(right != nullptr) {
            Line* line = new Line(w);
            line->set(x + (7 * letters.length() + 7)/2, y + 15, x + y / (index + 1)+ (7 * letters.length() + 7)/2, y + 50);
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
