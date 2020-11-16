#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QVBoxLayout* layout = nullptr;
    QWidget* mainWidget = nullptr;
    QScrollArea* renderArea = nullptr;
    void treatInput(QLineEdit* l);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
};
#endif // MAINWINDOW_H
