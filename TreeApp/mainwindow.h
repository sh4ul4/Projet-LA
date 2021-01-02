#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QGridLayout* layout = nullptr;
    QWidget* mainWidget = nullptr;
    QScrollArea* renderArea = nullptr;
    void treatInputTree(QLineEdit* input);
    void treatInputBinary(QLineEdit* input, QTextEdit* output);
    void treatInputCoded(QLineEdit* input, QTextEdit* output);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
};
#endif // MAINWINDOW_H
