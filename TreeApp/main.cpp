#include "Tree.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color: black;");
    Sommet c("C",2);
    Sommet b("B",6);
    Sommet cb = c + b;
    Sommet e("E",7);
    Sommet ecb = e + cb;
    Sommet _("_",10);
    Sommet d("D",10);
    Sommet _d = _ + d;
    Sommet a("A",11);
    Sommet aecb = ecb + a;
    Sommet _daecb = _d + aecb;

    ArbreB tree(_daecb);

    std::cout << tree.search("A") << std::endl;
    tree.print(&w,w.width()/2,100);
    w.show();
    return app.exec();
}
