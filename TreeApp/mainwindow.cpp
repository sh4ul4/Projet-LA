#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QLineEdit>
#include <iostream>

void MainWindow::treatInput(QLineEdit* l) {
    std::cout << "input treated : " << l->text().toStdString() << std::endl;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    this->setFixedSize(920,640);
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

    /*QMdiArea* mdiarea = new QMdiArea();

    QInputDialog* d = new QInputDialog(mdiarea);
    d->setLabelText("test2");
    d->setInputMode(QInputDialog::TextInput);
    layout->addWidget(mdiarea);*/

    mainWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{

}

