#pragma once

#include <iostream>
#include <string>

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QMessageBox>

template<typename T>
const T& min(const T& a, const T& b) {
    return a < b ? a :b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return a > b ? a :b;
}

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
        this->setGeometry(min(ax,bx), min(ay,by), max(ax,bx) - min(ax,bx), max(ay,by) - min(ay,by));
        painter.setPen(QPen(Qt::white, 4, Qt::SolidLine, Qt::RoundCap));
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
        painter.drawLine(ax - min(ax,bx) , ay - min(ay,by) , bx - min(ax,bx) , by - min(ay,by));
    }
};

class Sommet{
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
    /////////////////////////////////////////////////////////
    void clickedSlot()const {
        QMessageBox msg;
        std::string txt = letters;
        txt += " ";
        txt += std::to_string(value);
        msg.setText(txt.c_str());
        msg.exec();
    }
    void print(MainWindow* w, int x, int y, int index) const {
        // left line
        if(left != nullptr) {
            Line* line = new Line(w);
            line->set(x + (7 * letters.length() + 7)/2, y , x - y / (index + 1)+ (7 * left->letters.length() + 7)/2, y + 54);
        } // right line
        if(right != nullptr) {
            Line* line = new Line(w);
            line->set(x + (7 * letters.length() + 7)/2, y , x + y / (index + 1)+ (7 * right->letters.length() + 7)/2, y + 54);
        }
        // Label
        /*QLabel* label = new QLabel(w);
        label->setText(letters.c_str());
        label->setGeometry(x,y,7 * letters.length() + 7,15);
        label->setStyleSheet("border: 1px solid white; background-color: gray;");
        label->raise();*/
        // Button
        QPushButton* b = new QPushButton(w);
        b->setText(letters.c_str());
        b->setGeometry(x,y,7 * letters.length() + 7,15);
        b->setStyleSheet("border: 1px solid white; background-color: gray;");
        b->raise();
        w->connect( b, &QPushButton::clicked, [=](){clickedSlot();} );
        // Terminal
        //std::cout << letters << " " << value << std::endl;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if (left != nullptr) left->print(w,x - y / (index + 1), y + 50,leftIndex);
        if (right != nullptr) right->print(w,x + y / (index + 1), y + 50,rightIndex);


    }
    int search(std::string lookFor)const {
        int res = 0;
        if (letters == lookFor) res = value;
        if (left != nullptr) res += left->search(lookFor);
        if (right != nullptr) res += right->search(lookFor);
        return res;
    }
};
