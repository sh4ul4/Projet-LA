#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QInputDialog>
#include <QLabel>


class Panel : public QWidget
{
    int sizeX;
    int sizeY;

public:
    void setSizeX(const int& val);
    void setSizeY(const int& val);
    Panel();
};

#endif // PANEL_H
