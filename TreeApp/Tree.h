#pragma once
#include "Sommet.h"

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
