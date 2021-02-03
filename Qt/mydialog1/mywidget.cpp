#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDialog>
void MyWidget::on_showChildDialog_clicked()
{
    QDialog *dialog = new QDialog;
    dialog->show();
}

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->showChildButton,&QPushButton::clicked,this,&MyWidget::on_showChildDialog_clicked);



    //非模态对话框
    //QDialog *dialog = new QDialog;
    //dialog->show();
    //模态对话框（模态对话框在没关闭之前，不能再与同一个应用程序的其他窗口进行交互）
    //dialog.exec();
}

MyWidget::~MyWidget()
{
    delete ui;
}
