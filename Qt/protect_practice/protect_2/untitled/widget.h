#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPoint>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    
    //定义虚函数
     void mouseMoveEvent(QMouseEvent *event);
     void mousePressEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);

private slots:
     void on_MinBtn_clicked();

     void on_MaxBtn_clicked();

     void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QPoint z;

};

#endif // WIDGET_H
