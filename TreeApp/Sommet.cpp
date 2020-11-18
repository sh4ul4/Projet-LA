#include "Sommet.h"

Sommet::Sommet(std::string letters, int value) : letters(letters), value(value) {}
Sommet::Sommet(const Sommet& s) { /// copie du Sommet
    if (s.left != nullptr){ // copier la nouvelle valeur pour left
        delete left;
        left = new Sommet(*s.left);
    }
    if (s.right != nullptr) { // copier la nouvelle valeur pour right
        delete right;
        right = new Sommet(*s.right);
    }
    // copier les autres valeur
    value = s.value;
    letters = s.letters;
}
Sommet::~Sommet() /// libérer les variables allouées dynamiquement et leur donner une valeur neutre
{
    for(Line* l : lines)delete l;
    lines.clear();
    delete b;
    b = nullptr;
    delete label;
    label = nullptr;
    if(left != nullptr)delete left;
    left = nullptr;
    if(right != nullptr)delete right;
    right = nullptr;
}
void Sommet::setValue(const int& val) {
    value = val;
}
void Sommet::setLeft(const Sommet& s) {
    // copie des valeurs de la base du Sommet
    const std::string letters = s.getLetters();
    const int value = s.getValue();
    delete left; // libérer la mémoire de l'ancien Sommet left
    left = new Sommet(letters,value); // création de la base du Sommet
    if(s.left!=nullptr)left->setLeft(*s.left); // appel récursif gauche
    if(s.right!=nullptr)left->setRight(*s.right); // appel récursif droit
}
void Sommet::setRight(const Sommet& s) {
    // copie des valeurs de la base du Sommet
    const std::string letters = s.getLetters();
    const int value = s.getValue();
    delete right; // libérer la mémoire de l'ancien Sommet right
    right = new Sommet(letters,value); // création de la base du Sommet
    if(s.left!=nullptr)right->setLeft(*s.left); // appel récursif gauche
    if(s.right!=nullptr)right->setRight(*s.right); // appel récursif droit
}
int Sommet::getValue()const { return value; }
std::string Sommet::getLetters()const { return letters; }
Sommet Sommet::operator+(const Sommet& s)const /// concaténation de deux objets Sommet en créant un nouveau Sommet base
{
    // gérer les cas erreur
    if (left != nullptr&&left->search(s.letters) > 0) {
        std::cout << "letters already exist in subSommet" << std::endl;
        exit(1);
    }
    if (right != nullptr&&right->search(s.letters) > 0) {
        std::cout << "letters already exist in subSommet" << std::endl;
        exit(1);
    }
    // la valeur la plus petite doit être à droite
    if (this->value > s.getValue()) {
        // création du Sommet base
        Sommet res(this->letters + s.getLetters(), this->value + s.getValue());
        // lancer les copies récursives
        res.setLeft(*this);
        res.setRight(s);
        return res;
    }
    else {
        // création du Sommet base
        Sommet res(s.getLetters() + this->letters, this->value + s.getValue());
        // lancer les copies récursives
        res.setLeft(s);
        res.setRight(*this);
        return res;
    }
}
bool operator<(const Sommet& a, const Sommet& b) {
    return a.getValue() < b.getValue();
}
bool operator>(const Sommet& a, const Sommet& b) {
    return a.getValue() > b.getValue();
}
void Sommet::clickedSlot(Panel* panel, const int& x, const int& y) /// réagir aux clicks des instances QPushButton
{
    if(label == nullptr) {
        std::string txt = letters;
        txt += " ";
        txt += std::to_string(value);
        delete label;
        label = new QLabel(panel);
        label->setText(txt.c_str());
        label->setGeometry(x,y + 20,9 * txt.length() + (int)(value/10 + 1) * 9,15);
        label->setStyleSheet("border: 1px solid white; background-color: gray;");
        label->raise();
        label->show();
        label->adjustSize();
        //panel->setSizeX(x+7 * txt.length() + (int)(value/10 + 1) * 9); // adapt panel width
        //panel->setSizeY(y+35); // adapt panel height
    } else {
        delete label;
        label = nullptr;
    }
}
void Sommet::printLines(Panel* panel) /// afficher les lignes correspondantes aux objets Sommet dans la GUI
{
    // lines needs to be cleared before recursive call
    for(Line* l : lines)delete l;
    lines.clear();
    // print left line
    if(left != nullptr && b != nullptr && left->b != nullptr) {
        lines.push_back(new Line(panel,b->x() + b->width() + 1, b->y() + b->height()/2 , left->b->x() + 2, left->b->y() + left->b->height()/2));
        left->printLines(panel);
    }
    // print right line
    if(right != nullptr && b != nullptr && right->b != nullptr) {
        lines.push_back(new Line(panel,b->x() + b->width()/2, b->y() + b->height() + 2 , right->b->x() + right->b->width()/2, right->b->y() + 2));
        right->printLines(panel);
    }
}
void Sommet::print(Panel* panel, const int& x, const int& y) /// afficher les valeurs des objets Sommet dans la GUI
{
    // Button
    delete b;
    b = new QPushButton(panel);
    b->setText(letters.c_str());
    b->setGeometry(x,y,9 * letters.length() ,20);
    b->setStyleSheet("border: 1px solid white; background-color: gray;");
    panel->connect( b, &QPushButton::clicked, [=](){clickedSlot(panel,x,y);} );
    //panel->setSizeX(x+9 * letters.length() ); // adapt panel width
    //panel->setSizeY(y+20); // adapt panel height
    panel->adjustSize();
    // recursivité
    // print gauche
    if (left != nullptr){
        left->print(panel,x + 20  + letters.length() * 9, y);
    }
    // incrementation de variable Buttonid
    Sommet::Buttonind += 20;
    // print droit
    if (right != nullptr) {
        right->print(panel,x, Sommet::Buttonind);
    }
    // Terminal
    //std::cout << letters << " " << value << std::endl;
}
int Sommet::search(const std::string lookFor)const /// renvoie 0 si la valeur n'est pas présente, sinon la valeur correspondante
{
    int res = 0;
    if (letters == lookFor) res = value;
    if (left != nullptr) res += left->search(lookFor);
    if (right != nullptr) res += right->search(lookFor);
    return res;
}

