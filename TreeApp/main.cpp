#include "Tree.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;

    Sommet a("A", 3);
    Sommet b("B", 1);
    Sommet s1("E", 1);
    Sommet s2("F", 2);
    Sommet s3("G", 9);
    Sommet s4("H", 4);
    Sommet s5("I", 6);
    Sommet s6("J", 2);
    Sommet c = a + b + s1 + s2 + s3 + s4;
    //ArbreB tree1(c,&scene,&view);
    //Sommet d("C", 30);
    //ArbreB tree2(d,&scene,&view);
    //d = d + s5 + s6;
    //ArbreB tree3 = tree1 + tree2;
    ArbreB tree(c);

    std::cout << tree.search("A") << std::endl;
    tree.print(&w,100,100);
    w.show();
    return app.exec();
}
