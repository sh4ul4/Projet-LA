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
    renderArea->setObjectName("RENDERAREA");
    renderArea->setStyleSheet(QString(
                                  "QWidget#RENDERAREA {"
                                  "background-color: black;"
                                  " border-style: outset;"
                                  " border-width: 2px;"
                                  " border-radius: 10px;"
                                  " border-color: gray;"
                                  " font: bold 14px;"
                                  " min-width: 10em;"
                                  " padding: 6px;} "
                                  "QScrollBar:horizontal {"
                                       "height: 15px;"
                                       "margin: 3px 15px 3px 15px;"
                                       "border: 1px transparent #2A2929;"
                                       "border-radius: 4px;"
                                       "background-color: #2A2929; }"
                                   "QScrollBar::handle:horizontal {"
                                       "background-color: gray;"
                                       "min-width: 5px;"
                                       "border-radius: 4px; }"
                                   "QScrollBar::add-line:horizontal {"
                                       "margin: 0px 3px 0px 3px;"
                                       "width: 10px;"
                                       "height: 10px;"
                                       "subcontrol-position: right;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::sub-line:horizontal {"
                                       "margin: 0px 3px 0px 3px;"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: left;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::add-line:horizontal:hover,QScrollBar::add-line:horizontal:on {"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: right;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::sub-line:horizontal:hover, QScrollBar::sub-line:horizontal:on {"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: left;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal {"
                                       "background: none; }"
                                   "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
                                       "background: none; }"
                                   "QScrollBar:vertical {"
                                       "background-color: #2A2929;"
                                       "width: 15px;"
                                       "margin: 15px 3px 15px 3px;"
                                       "border: 1px transparent #2A2929;"
                                       "border-radius: 4px; }"
                                   "QScrollBar::handle:vertical {"
                                       "background-color: gray;"
                                       "min-height: 5px;"
                                       "border-radius: 4px; }"
                                   "QScrollBar::sub-line:vertical {"
                                       "margin: 3px 0px 3px 0px;"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: top;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::add-line:vertical {"
                                       "margin: 3px 0px 3px 0px;"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: bottom;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::sub-line:vertical:hover,QScrollBar::sub-line:vertical:on {"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: top;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::add-line:vertical:hover, QScrollBar::add-line:vertical:on {"
                                       "height: 10px;"
                                       "width: 10px;"
                                       "subcontrol-position: bottom;"
                                       "subcontrol-origin: margin; }"
                                   "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
                                       "background: none; }"
                                   "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                                       "background: none; }"));
    //renderArea->setWidgetResizable( true );
    renderArea->setGeometry(20,20,0,0);
    renderArea->setMinimumSize(500,600);
    layout->addWidget(renderArea);

    QLineEdit* l = new QLineEdit();
    //l->setObjectName("TEXTINPUT");
    //l->setStyleSheet("QWidget#TEXTINPUT {background-color: gray; border-style: outset; border-color: gray;border-radius: 5px;}");
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

