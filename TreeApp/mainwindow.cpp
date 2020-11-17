#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QLineEdit>
#include <iostream>
#include "Tree.h"

void MainWindow::treatInput(QLineEdit* l) {
    // récupérer les lettres en entrée
    std::string text = l->text().toStdString();
    // construire la variable statique globalTree
    ArbreB::GlobalTree(text);
    // afficher l'arbre
    if(ArbreB::globalTree != nullptr)ArbreB::globalTree->print(this);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(920,640);

    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    layout = new QVBoxLayout();

    renderArea = new QScrollArea();
    renderArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    renderArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    renderArea->viewport()->setBackgroundRole(QPalette::Shadow);
    //renderArea->setWidgetResizable( true );
    renderArea->setGeometry(20,20,0,0);
    renderArea->setMinimumSize(500,600);
    layout->addWidget(renderArea);

    QLineEdit* l = new QLineEdit();
    mainWidget->connect( l, &QLineEdit::textChanged, [=](){treatInput(l);} );
    layout->addWidget(l);

    mainWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ArbreB::globalTree;
    delete layout;
    delete mainWidget;
}

