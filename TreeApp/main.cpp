#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include "Tree.h"

int main(int argc, char *argv[]) {
    Sommet a("A", 3);
    Sommet b("B", 1);
    Sommet c = a + b;
    ArbreB tree1(c);
    Sommet d("C", 2);
    ArbreB tree2(d);
    ArbreB tree = tree1 + tree2;
    tree.print();
    std::cout << tree.search("A") << std::endl;

    QApplication app(argc, argv);
    MainWindow w;
    QLabel label ("A",&w);
    label.setGeometry(100,100,10,10);
    w.show();
    return app.exec();
}
