#include "Sommet.h"

Sommet::Sommet(std::string letters, int value) : letters(letters), value(value) {}
Sommet::Sommet(const Sommet& s) {
    if (s.left != nullptr) left = new Sommet(*s.left);
    if (s.right != nullptr) right = new Sommet(*s.right);
    value = s.value;
    letters = s.letters;
}
Sommet::~Sommet() {
    delete left;
    delete right;
}
void Sommet::setLeft(const Sommet& s) {
    if(left != nullptr)delete left;
    Sommet* newS = new Sommet(s);
    left = newS;
}
void Sommet::setRight(const Sommet& s) {
    if(right != nullptr)delete right;
    Sommet* newS = new Sommet(s);
    right = newS;
}
int Sommet::getValue()const { return value; }
std::string Sommet::getLetters()const { return letters; }
Sommet Sommet::operator+(const Sommet& s)const  {
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
void Sommet::clickedSlot()const {
    QMessageBox msg;
    std::string txt = letters;
    txt += " ";
    txt += std::to_string(value);
    msg.setText(txt.c_str());
    msg.exec();
}
void Sommet::print(MainWindow* w, const int& x, const int& y, const int& index) const {
    // left line
    if(left != nullptr) {
        Line* const line = new Line(w);
        line->set(x + (7 * letters.length() + 7)/2, y , x - y / (index + 1)+ (7 * left->letters.length() + 7)/2, y + 54);
    }
    // right line
    if(right != nullptr) {
        Line* const line = new Line(w);
        line->set(x + (7 * letters.length() + 7)/2, y , x + y / (index + 1)+ (7 * right->letters.length() + 7)/2, y + 54);
    }
    // Label
    /*QLabel* label = new QLabel(w);
    label->setText(letters.c_str());
    label->setGeometry(x,y,7 * letters.length() + 7,15);
    label->setStyleSheet("border: 1px solid white; background-color: gray;");
    label->raise();*/
    // Button
    QPushButton* const b = new QPushButton(w);
    b->setText(letters.c_str());
    b->setGeometry(x,y,7 * letters.length() + 7,15);
    b->setStyleSheet("border: 1px solid white; background-color: gray;");
    b->raise();
    w->connect( b, &QPushButton::clicked, [=](){clickedSlot();} );
    // Terminal
    //std::cout << letters << " " << value << std::endl;
    // recursivity
    const int leftIndex = 2 * index + 1;
    const int rightIndex = 2 * index + 2;
    if (left != nullptr) left->print(w,x - y / (index + 1), y + 50,leftIndex);
    if (right != nullptr) right->print(w,x + y / (index + 1), y + 50,rightIndex);
}
int Sommet::search(const std::string lookFor)const {
    int res = 0;
    if (letters == lookFor) res = value;
    if (left != nullptr) res += left->search(lookFor);
    if (right != nullptr) res += right->search(lookFor);
    return res;
}

