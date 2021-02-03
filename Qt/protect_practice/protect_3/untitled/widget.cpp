#include "widget.h"
#include "ui_widget.h"
#include<QGraphicsDropShadowEffect>
#include<QColor>
#include<QMouseEvent>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QCryptographicHash>
#include<QApplication>
#include<QDir>
#include<QFileInfo>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread.start();  //启动线程
    md5.moveToThread(&thread);


    this->setWindowFlags(Qt::FramelessWindowHint); //设置窗口为无边框效果

    //ui->shadowWidget->setStyleSheet("QWidget{border-radius:5px;}");
    ui->frame->setGraphicsEffect(shadow);

    //设置父窗口为透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    connect(&md5, SIGNAL(getDrumplate(QHash<QByteArray, QStringList>)), this, SLOT(on_getDrumplate(QHash<QByteArray, QStringList>)));
    connect(this, SIGNAL(checkDumplate( QString)), &md5, SLOT(checDumplate(QString)));
    connect(&md5, SIGNAL(progress(int, int)), this, SLOT(on_progress(int, int)));
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


void Widget::on_Minbutton_clicked()
{
    this->showMinimized();
}

void Widget::on_Maxbutton_clicked()
{
    main_widget->setWindowState(Qt::WindowMaximized);

}

void Widget::on_Closebutton_clicked()
{
    this->close();
}



void Widget::on_Filebutton_clicked()
{
    QFile file("C:/Users/20835/Desktop/123.txt");
    if(file.open(QIODevice::ReadOnly)){

        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
            QByteArray content = file.read(100 * 1024 * 1024);
            hash.addData(content);
            qApp->processEvents();
        }
        qDebug()<<"Md5:"<< hash.result();
         //QByteArray md5 = hash.result();
        // QByteArray content = file.readAll();
        //QMessageBox::information(this,"title", content);
        //QByteArray md5 =  QCryptographicHash::hash(content,QCryptographicHash::Md5);

        file.close();
    }
}



Widget::~Widget()
{
    thread.exit();
    thread.wait(10*1000);
    delete ui;
}


void Widget::on_getfile_clicked()
{
    emit checkDumplate("D:\\word");

    //md5.checDumplate("D:\\word");
}

void Widget::on_getDrumplate(const QHash<QByteArray, QStringList> &dumplates)
{
    for(QHash<QByteArray, QStringList>::const_iterator itr = dumplates.begin(); itr != dumplates.end(); itr++)
    {
        qDebug()<<"md5:"<< itr.key() <<"count:"<<itr.value().count();
        if (itr.value().count() > 1)
        {
            qDebug() << "file:" << itr.value();

        }
    }
}

void Widget::on_progress(int current, int total)
{
    ui->progressBar->setValue(current);
    ui->progressBar->setMaximum(total);
}
