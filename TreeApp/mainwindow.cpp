#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QLineEdit>
#include <iostream>
#include "Tree.h"

void MainWindow::treatInputTree(QLineEdit* input) /// construire un ArbreB avec le texte de la GUI en entrée
{
    // récupérer les lettres en entrée
    std::string text = input->text().toStdString();
    if(text.empty())return;
    // construire une instance d'arbre pour l'affichage
    ArbreB::createPrintInstance(text);
    // afficher l'arbre
    if(ArbreB::printInstance != nullptr)ArbreB::printInstance->print(this);
}

void MainWindow::treatInputBinary(QLineEdit* input, QTextEdit* output) /// 
{
	// récupérer les lettres en entrée
    std::string text = input->text().toStdString();
    if(text.empty())return;
    // écrire le résultat dans la sortie texte
    if(ArbreB::printInstance != nullptr){
    	QString res = QString::fromStdString(ArbreB::printInstance->codeText(text));
    	output->setText(res);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //this->setFixedSize(920,640);
    this->setMinimumSize(400,200);

    mainWidget = new QWidget(this);
    mainWidget->setObjectName("MAINWIDGET");
    mainWidget->setStyleSheet("QWidget#MAINWIDGET {background-color: #1b2d5e;}");
    setCentralWidget(mainWidget);

    layout = new QGridLayout();

    renderArea = new QScrollArea();
    renderArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    renderArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    renderArea->viewport()->setBackgroundRole(QPalette::Shadow);
    renderArea->setObjectName("RENDERAREA");
    renderArea->setStyleSheet(QString(
                                  "QWidget#RENDERAREA {"
                                  "background-color: #145573;"
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
    renderArea->setGeometry(20,20,0,0);
    renderArea->setMinimumSize(200,200);

    QLineEdit* textInput = new QLineEdit();
    textInput->setObjectName("TEXTINPUT");
    textInput->setStyleSheet("QWidget#TEXTINPUT {color: #145573; background-color: beige;}");

    QTextEdit* textOutput = new QTextEdit();
    textOutput->setStyleSheet("background : white");
    textOutput->setReadOnly(true);
    textOutput->setLineWrapColumnOrWidth(600);
    textOutput->setObjectName("TEXTOUTPUT");
    textOutput->setStyleSheet(QString(
                                  "QWidget#TEXTOUTPUT {"
                                  "background-color: #145573;"
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
	textOutput->setTextColor(QColorConstants::Svg::beige);

    QLineEdit* textInput2 = new QLineEdit();
    textInput2->setObjectName("TEXTINPUT2");
    textInput2->setStyleSheet("QWidget#TEXTINPUT2 {color: #145573; background-color: beige;}");

    mainWidget->connect( textInput, &QLineEdit::returnPressed, [=](){treatInputTree(textInput);} );
    mainWidget->connect( textInput2, &QLineEdit::returnPressed, [=](){treatInputTree(textInput);} );
    mainWidget->connect( textInput2, &QLineEdit::returnPressed, [=](){treatInputBinary(textInput2,textOutput);} );
    mainWidget->connect( textInput, &QLineEdit::returnPressed, [=](){treatInputBinary(textInput2,textOutput);} );

    layout->addWidget(renderArea,0,0);
    layout->addWidget(textOutput,0,1);
    layout->addWidget(textInput,1,0);
    layout->addWidget(textInput2,1,1);

    mainWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ArbreB::printInstance;
    delete layout;
    delete mainWidget;
}

