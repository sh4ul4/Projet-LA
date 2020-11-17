#include "Sommet.h"

Sommet::Sommet(std::string letters, int value) : letters(letters), value(value) {}
Sommet::Sommet(const Sommet& s) { // copie du Sommet
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
Sommet::~Sommet() // libérer les variables allouées dynamiquement et leur donner une valeur neutre
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
Sommet Sommet::operator+(const Sommet& s)const // concaténation de deux objets Sommet en créant un nouveau Sommet base
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
    if (this->value < s.getValue()) {
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
void Sommet::clickedSlot(Panel* panel, const int& x, const int& y) // réagir aux clicks des instances QPushButton
{
    if(label == nullptr) {
        std::string txt = letters;
        txt += " ";
        txt += std::to_string(value);
        delete label;
        label = new QLabel(panel);
        label->setText(txt.c_str());
        label->setGeometry(x,y + 20,7 * txt.length() + 7,15);
        label->setStyleSheet("border: 1px solid white; background-color: gray;");
        label->raise();
        label->show();
        panel->setSizeX(x+7 * txt.length() + 7); // adapt panel width
        panel->setSizeY(y+35); // adapt panel height
    } else {
        delete label;
        label = nullptr;
    }
}
void Sommet::print(Panel* panel, const int& x, const int& y, const int& index) {
    // lines needs to be cleared before recursive call
    for(Line* l : lines)delete l;
    lines.clear();
    // left line
    if(left != nullptr) {
        lines.push_back(new Line(panel));
        lines[lines.size() - 1]->set(x + (7 * letters.length() + 7)/2, y , x - y / (index + 1)+ (7 * left->letters.length() + 7)/2, y + 54);
    }
    // right line
    if(right != nullptr) {
        lines.push_back(new Line(panel));
        lines[lines.size() - 1]->set(x + (7 * letters.length() + 7)/2, y , x + y / (index + 1)+ (7 * right->letters.length() + 7)/2, y + 54);
    }
    // Button
    delete b;
    b = new QPushButton(panel);
    b->setText(letters.c_str());
    b->setGeometry(x,y,7 * letters.length() + 7,15);
    b->setStyleSheet("border: 1px solid white; background-color: gray;");
    panel->connect( b, &QPushButton::clicked, [=](){clickedSlot(panel,x,y);} );
    panel->setSizeX(x+7 * letters.length() + 7); // adapt panel width
    panel->setSizeY(y+15); // adapt panel height

    // Terminal
    //std::cout << letters << " " << value << std::endl;
    // recursivité
    const int leftIndex = 2 * index + 1;
    const int rightIndex = 2 * index + 2;
    if (left != nullptr) left->print(panel,x - y / (index + 1), y + 50,leftIndex);
    if (right != nullptr) right->print(panel,x + y / (index + 1), y + 50,rightIndex);
}
int Sommet::search(const std::string lookFor)const // renvoie 0 si la valeur n'est pas présente, sinon la valeur correspondante
{
    int res = 0;
    if (letters == lookFor) res = value;
    if (left != nullptr) res += left->search(lookFor);
    if (right != nullptr) res += right->search(lookFor);
    return res;
}

