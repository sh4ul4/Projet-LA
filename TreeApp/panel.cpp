#include "panel.h"

Panel::Panel()
{
    sizeX = 0;
    sizeY = 0;
}

void Panel::setSizeX(const int& val) // définir une largeur maximale
{
    if(val > sizeX)sizeX = val;
    this->setFixedWidth(sizeX);
}
void Panel::setSizeY(const int& val) // définir une hauteur maximale
{
    if(val > sizeY)sizeY = val;
    this->setFixedHeight(sizeY);
}
