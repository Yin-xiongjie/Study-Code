#include<QWidget>
#include<QApplication>
#include<QLabel>
#include<QDebug>
int main(int argc, char * argv[])
{
/**********************2020-9-24*******************/
/******************作者：尹雄杰********************/
/******************用途：测试练习******************/
/***************空项目C++书写窗口******************
    QApplication a(argc, argv);
    //新建QWidget对象
    QWidget *widget = new QWidget();
    //设置窗口标题
    widget->setWindowTitle(QObject::tr("I am Widget!"));
    //新建QLabel对象
    QLabel *label1 = new QLabel();
    //设置label1标题
    label1->setWindowTitle(QObject::tr("I am label1!"));
    //设置要显示的信息
    label1->setText(QObject::tr("label:就是个窗口！"));
    //设置label样式
    label1->setStyleSheet("background-color:rgb(255,0,0);color:#000;font-style:italic;font-family:Microsoft Yahei;font-size: 17px;font-weight:bold");
    label1->setAlignment(Qt::AlignCenter);
    //设置部件大小
    label1->resize(300,200);
    //设置label2的父窗口为widget,so widget is not a window
    QLabel *label2 = new QLabel(widget);
    //设置label2标题
    label2->setWindowTitle(QObject::tr("I am label2!"));
    //设置label2显示的信息
    label2->setText(QObject::tr("label2:我不是独立窗口，我只是widget的子部件！"));
    label2->setStyleSheet("background-color:rgb(236,248,250);color:#0f0;font-family:黑体;font-size: 14px;font-weight:bold");
    label2->setAlignment(Qt::AlignCenter);
    label2->resize(400,200);

    //显示窗口
    widget->show();
    label1->show();
    int ret = a.exec();
    delete label1;
    delete widget;
    return ret;
********************注释结束**************************/

    /**********************2020-9-24*******************/
    /******************作者：尹雄杰********************/
    /******************用途：测试练习******************/
    /***************空项目C++程序调试******************/
        QApplication a(argc, argv);
        QWidget widget;
        widget.resize(400,300);
        widget.move(200,100);
        widget.show();
        int x = widget.x();
        qDebug("x:%d",x);
        int y = widget.y();
        qDebug("y:%d",y);
        QRect geometry = widget.geometry();//返回没有边框的的窗口框架矩形的值
        QRect frame = widget.frameGeometry();//返回有边框的的窗口框架矩形的值
        qDebug()<<"geometry:"<<geometry<<"frame:"<<frame;
        qDebug()<<"pos:"<<widget.pos()<<endl<<"rect:"<<widget.rect()
                        <<endl<<"size:"<<widget.size()<<endl<<"width:"
                        <<widget.width()<<endl<<"height:"<<widget.height();
        return a.exec();
}
