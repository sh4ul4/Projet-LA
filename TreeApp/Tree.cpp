#include "Tree.h"

ArbreB::ArbreB(const Sommet& root) :root(root) {}
const ArbreB ArbreB::operator+(const ArbreB& t) {
    ArbreB res(root + t.root);
    return res;
}
void ArbreB::print(MainWindow* w, const int& x, const int& y)const {
    root.print(w,x - root.getLetters().size() * 7 / 2,y, 0);
}
void ArbreB::print(MainWindow* w)const {
    root.print(w,w->width()/2 - root.getLetters().size() * 7 / 2,75, 0);
}
int ArbreB::search(std::string lookFor)const {
    return root.search(lookFor);
}
