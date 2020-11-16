#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QLineEdit>
#include <iostream>
#include "Tree.h"

int contains(const std::vector<Sommet*>& vec,const std::string& c) {
    for(int i = 0; i < (int)vec.size(); i++){
        if(vec[i]->getLetters() == c)return i;
    } return -1;
}

struct compareFct {
    bool operator()(Sommet* a, Sommet* b) {
        return a->getValue() < b->getValue();
    }
};

void MainWindow::treatInput(QLineEdit* l) {
    //std::cout << "ok1" << std::endl;
    std::string text = l->text().toStdString();
    //std::cout << "input treated : " << text << std::endl;
    std::vector<Sommet*> sommets;
    for(char c : text) {
        int index = contains(sommets,std::string(1,c));
        if(index >= 0) sommets[index]->setValue(sommets[index]->getValue()+1);
        else {
            sommets.push_back(new Sommet(std::string(1,c),1));
            //std::cout << "new letter : " << std::string(1,c) << std::endl;
        }
    }
    delete ArbreB::globalTree;
    if(sommets.size() == 0){
        return;
    }
    // build tree
    while(sommets.size() > 1){
        std::sort(sommets.begin(), sommets.end(), compareFct());
        Sommet tmp = *sommets[0] + *sommets[1];
        delete sommets[0];
        sommets.erase(sommets.begin());
        delete sommets[0];
        sommets.erase(sommets.begin());
        sommets.push_back(new Sommet(tmp));
    }

    ArbreB::globalTree = new ArbreB(*sommets[0]);
    ArbreB::globalTree->print(this);
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
}

