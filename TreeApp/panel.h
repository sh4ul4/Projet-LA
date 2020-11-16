#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>


class Panel : public QWidget
{

    int sizeX;
    int sizeY;
public:
    void setSizeX(const int& val){
        if(val > sizeX)sizeX = val;
        this->setFixedWidth(sizeX);
    }
    void setSizeY(const int& val){
        if(val > sizeY)sizeY = val;
        this->setFixedHeight(sizeY);
    }

    Panel();
};

#endif // PANEL_H
