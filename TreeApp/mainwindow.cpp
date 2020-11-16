#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(920,640);
    renderArea = new QScrollArea(this);
    renderArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    renderArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    renderArea->viewport()->setBackgroundRole(QPalette::Shadow);
    //renderArea->setWidgetResizable( true );
    renderArea->setGeometry(20,20,0,0);
    renderArea->setMinimumSize(500,600);
}

MainWindow::~MainWindow()
{

}

