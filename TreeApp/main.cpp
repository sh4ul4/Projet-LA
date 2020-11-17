#include "Tree.h"
ArbreB* ArbreB::globalTree = nullptr;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.setObjectName("MAINW");
    w.setStyleSheet("QWidget#MAINW {background-color: black;}");
    w.show();
    return app.exec();
}
