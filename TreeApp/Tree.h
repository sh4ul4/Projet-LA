#pragma once
#include "Sommet.h"
#include "mainwindow.h"
#include <unordered_map>

class ArbreB {
public:
    static ArbreB* printInstance; // variable statique qui pointe vers l'arbre à afficher
    Sommet* root;
    std::unordered_map<char, std::string> charToBinary;
    std::unordered_map<std::string, char> binaryToChar; // map de conversion entre d'un code binaire en un char
public:
    ArbreB() = delete;
    ArbreB(const Sommet& root); // obligation de créer un objet ArbreB avec un Sommet root prédéfini
    static void createPrintInstance(std::string text); // créer une instance statique d'arbre pour l'affichage
    ~ArbreB(); // destructeur
    ArbreB & operator = (const ArbreB& t);
    const ArbreB operator+(const ArbreB& t); // addition de deux objet ArbreB et création d'un nouveau Sommet root en fonction des sous-sommets
    void print(MainWindow* w); // print the Tree in GUI
    int search(std::string lookFor)const; // renvoyer la valeur du contenu correspondant (récursif) ou 0 autrement
    std::string encodeText(const std::string text); // renvoit le texte entré en texte binaire codé selon le code de huffman de l'arbre. Renvoit "Error" si le texte n'est pas codé selon le même langage.
    std::string decodeBinary(const std::string binary); // renvoit le code binaire décodé en texte lisible. renvoit "Error" si le texte n'est pas décodable par l'arbre.
};
