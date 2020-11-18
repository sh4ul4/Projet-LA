#include "line.h"

template<typename T>
const T& min(const T& a, const T& b) {
    return a < b ? a :b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return a > b ? a :b;
}

Line::Line(QWidget* parent, int ax, int ay, int bx, int by):QWidget(parent),ax(ax),ay(ay),bx(bx),by(by){}
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
    this->setGeometry(min(ax,bx) - 4, min(ay,by) - 4, max(ax,bx) - min(ax,bx) + 4, max(ay,by) - min(ay,by) + 4);
    painter.setPen(QPen(Qt::white, 4, Qt::SolidLine, Qt::FlatCap));
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.drawLine(ax - min(ax,bx) + 2, ay - min(ay,by) + 2, bx - min(ax,bx) + 2, by - min(ay,by) + 2);
}
