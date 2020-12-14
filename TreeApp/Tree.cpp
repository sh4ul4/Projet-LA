#include "Tree.h"

ArbreB::ArbreB(const Sommet& root)
{
    // création de la base du root par copie des valeurs
    this->root = new Sommet(root.getLetters(),root.getValue());
    // copie récursive des valeurs
    if(root.left!=nullptr)this->root->setLeft(*root.left);
    if(root.right!=nullptr)this->root->setRight(*root.right);
}
const ArbreB ArbreB::operator+(const ArbreB& t) // addition de deux arbres par copie et concaténation
{
    ArbreB res(*root + *t.root);
    return res;
}
ArbreB::~ArbreB() // destructeur
{
    delete root;
    root = nullptr;
}

int contains(const std::vector<Sommet*>& vec,const std::string& c) /// renvoie -1 si le string ne se trouve pas dans le vecteur, l'indice autrement
{
    for(int i = 0; i < (int)vec.size(); i++){
        if(vec[i]->getLetters() == c)return i;
    } return -1;
}

void triSommetList(std::vector<Sommet*>& vec) {
    std::vector<Sommet*>tmp;
    for (Sommet* s : vec) {
        if (!tmp.empty()) {
            for (int i = 0; i < (int)tmp.size(); i++) {
                if (s->getValue() < tmp[i]->getValue()) {   // fix les operateurs < & >
                    tmp.insert(tmp.begin() + i, s);
                    break;
                }
                if (i == (int)tmp.size() - 1) {
                    tmp.push_back(s);
                    break;
                }
            }
        }
        else {
            tmp.push_back(s);
        }
    }
    vec = tmp;







    /*for (int i = 0; i < (int)vec.size(); i++) {
        if (!tmp.empty()) {
            for (int j = 0; j < (int)tmp.size(); j++) {
                if (i == (int)vec.size()-1) {
                    tmp.push_back(vec[i]);
                    break;
                }
                if (vec[i]->getValue() < tmp[j]->getValue()) {
                    tmp.insert(tmp.begin() + j, vec[i]);
                    break;
                }
            }
        }
        else {
            tmp.push_back(vec[i]);
        }
    }
    vec = tmp;*/
}

void ArbreB::createPrintInstance(std::string text) /// créer une instance statique d'arbre pour l'affichage
{
    std::vector<Sommet*>sommets; // vecteur des sommets feuilles
    // ajout des objets Sommet (une lettre par sommet)
    for(char c : text) {
        int index = contains(sommets,std::string(1,c));
        if(index >= 0) sommets[index]->setValue(sommets[index]->getValue()+1);
        else {
            Sommet* tmp = new Sommet(std::string(1,c),1);
            sommets.push_back(tmp);
        }
    }
    // libérer la mémoire de la variable printInstance
    delete ArbreB::printInstance;
    ArbreB::printInstance = nullptr;
    // early exit si il n'y a pas de sommets
    if(sommets.size() == 0){
        for(Sommet* s : sommets)delete s;
        sommets.clear();
        return;
    }

    // construire l'arbre
    while(sommets.size() > 1){
        // trier le vecteur d'objets
        triSommetList(sommets);
        // créer un nouvel objet Sommet par copie et concaténation
        Sommet tmp = *sommets[0] + *sommets[1];
        // libérer la mémoire inutile au fur et à mesure
        delete sommets[0];
        sommets.erase(sommets.begin());
        delete sommets[0];
        sommets.erase(sommets.begin());
        // ajouter le nouvel objet Sommet créé
        sommets.push_back(new Sommet(tmp));
    }
    ArbreB::printInstance = new ArbreB(*sommets[0]); // créer le nouvel objet ArbreB par copie
    // libérer la mémoire restante
    delete sommets[0];
    sommets.clear();
    std::string test = ArbreB::printInstance->codeText("a_dead_dad_ceded_a_bad_babe_a_beaded_abaca_bed");
    int a = 1;
    a = 2;
}

void ArbreB::print(MainWindow* w) /// afficher l'arbre dans la GUI
{
    if(root == nullptr)return;
    Panel* panel = new Panel();
    panel->setObjectName("PANEL");
    panel->setStyleSheet(QString(
                         "QWidget#PANEL{"
                         "background-color: #121e26;}"));
    Sommet::Buttonind = 20;
    root->print(panel,20,20);
    w->renderArea->setWidget(panel);
}

int ArbreB::search(std::string lookFor)const /// renvoie 0 si la valeur n'est pas présente, sinon la valeur correspondante
{
    if(root == nullptr)return 0;
    return root->search(lookFor);
}

std::string ArbreB::codeText(const std::string text)  /// Converti un texte en code. Renvoit le texte codé, ou "Error" si le texte ne peux pas être codé.
{
    //################## Vérifie que le texte est écrit dans la même langue. ##################//

    // liste des lettres de l'arbre
    std::vector<char>charArbre; // vecteur de tout les chars de l'arbre
    for (char c: root->getLetters()) {
        charArbre.push_back(c);
    }
    // liste des lettres du texte
    std::vector<char>charText; // vecteur de tout les chars de l'arbre
    for (char c: text) {

        if (!(std::find(charText.begin(), charText.end(), c) != charText.end())) {
            charText.push_back(c);
        }
    }
    // comparaison
    for (char c: charText) {
        if (!(std::find(charArbre.begin(), charArbre.end(), c) != charArbre.end())) {
            return "Error"; // la lettre n'est pas présente dans l'arbre -> erreur
        }
    }
    //##################################### Code du texte #####################################//

    // creer le code binaire correspondant à chaques lettres
    std::vector<std::string>binaryText;
    for (char c: charArbre) {
        binaryText.push_back(root->getBinary(c));
    }
    // creer le code à partir des codes binaires de chaques lettres
    std::string code = "";
    for (char c: text) {
        code += binaryText[std::distance(charArbre.begin(), std::find(charArbre.begin(), charArbre.end(), c))];
    }
    return code;
}

ArbreB* ArbreB::printInstance = nullptr; /// variable statique qui pointe vers l'arbre à afficher
