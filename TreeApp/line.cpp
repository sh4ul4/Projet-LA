#include "line.h"

template<typename T>
const T& min(const T& a, const T& b) {
    return a < b ? a :b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return a > b ? a :b;
}
void Line::set(const int& ax,const int& ay,const int& bx,const int& by){
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
}
void Line::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    this->setGeometry(min(ax,bx), min(ay,by), max(ax,bx) - min(ax,bx), max(ay,by) - min(ay,by));
    painter.setPen(QPen(Qt::white, 4, Qt::SolidLine, Qt::RoundCap));
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.drawLine(ax - min(ax,bx) , ay - min(ay,by) , bx - min(ax,bx) , by - min(ay,by));
}
