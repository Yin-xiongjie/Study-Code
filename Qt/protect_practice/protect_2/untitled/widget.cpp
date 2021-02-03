#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QColor>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    this->setWindowFlags(Qt::FramelessWindowHint); //设置窗口为无边框效果

    //阴影边框
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();

    shadow->setBlurRadius(10); // 边缘阴影延伸量
    shadow->setColor(Qt::black);//阴影颜色
    shadow->setOffset(0);  //阴影偏移度
    //ui->shadowWidget->setStyleSheet("QWidget{border-radius:5px;}");
    ui->shadowWidget->setGraphicsEffect(shadow);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    QPoint y = event->globalPos(); //鼠标相对于桌面左上角的位置，鼠标全局位置；
    QPoint x = y - this->z;
    this->move(x);
}



void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QPoint y = event->globalPos(); //鼠标相对于桌面左上角的位置，鼠标全局位置；
    QPoint x = this->geometry().topLeft();//窗口左上角相对于桌面左上角的位置，窗口位置
    this->z = y - x;  //定值， 不变
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z = QPoint();
}

void Widget::on_MinBtn_clicked()
{
    this->showMinimized();
}

void Widget::on_MaxBtn_clicked()
{
    if (this->isMaximized())
    {
        this->showNormal();
    }else {
        this->setWindowState(Qt::WindowMaximized);
    }
}

void Widget::on_pushButton_3_clicked()
{
    this->close();
}
