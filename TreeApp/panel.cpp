#include "panel.h"
#include <QInputDialog>
#include <QLabel>

Panel::Panel()
{
    sizeX = 0;
    sizeY = 0;
    /*bool ok;
    QString text = QInputDialog::getText(this, "Input dialog",
    "String :", QLineEdit::Normal,
    "", &ok);
    if (ok && !text.isEmpty()) {
        QLabel* label = new QLabel(this);
        label->setText(text);
        label->setGeometry(10,10,100,100);
        label->setStyleSheet("border: 1px solid white; background-color: gray;");
        label->raise();
        label->show();
    }*/
}
