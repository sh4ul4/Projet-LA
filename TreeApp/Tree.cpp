#include "Tree.h"

ArbreB::ArbreB(const Sommet& root) :root(root) {}
const ArbreB ArbreB::operator+(const ArbreB& t) {
    ArbreB res(root + t.root);
    return res;
}
void ArbreB::print(MainWindow* w, const int& x, const int& y) {
    Panel* panel = new Panel();
    root.print(panel,x - root.getLetters().size() * 7 / 2,y, 0);
    w->renderArea->setWidget(panel);
}
void ArbreB::print(MainWindow* w) {
    Panel* panel = new Panel();
    root.print(panel,w->renderArea->width()/2 - root.getLetters().size() * 7 / 2,75, 0);
    w->renderArea->setWidget(panel);
}
int ArbreB::search(std::string lookFor)const {
    return root.search(lookFor);
}
