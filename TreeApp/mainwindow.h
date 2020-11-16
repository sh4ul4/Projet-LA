#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QVBoxLayout* layout;
    QWidget* mainWidget;
    QScrollArea* renderArea;
    void treatInput(QLineEdit* l);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
};
#endif // MAINWINDOW_H
