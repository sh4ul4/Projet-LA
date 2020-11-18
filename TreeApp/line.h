#ifndef LINE_H
#define LINE_H
#include <QWidget>
#include <QPainter>

class Line : public QWidget
{
    int ax,ay,bx,by;
public:
    explicit Line(QWidget* parent=nullptr, int ax = 0, int ay = 0, int bx = 0, int by = 0);
    void set(const int& ax,const int& ay,const int& bx,const int& by);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // LINE_H
