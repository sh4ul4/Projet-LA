#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QLabel label ("A",&w);
    label.setGeometry(100,100,10,10);
    w.show();
    return a.exec();
}
