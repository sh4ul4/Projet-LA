#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QScrollArea* renderArea;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
};
#endif // MAINWINDOW_H
