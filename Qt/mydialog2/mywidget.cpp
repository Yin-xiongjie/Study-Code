#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
   // QColorDialog::getColor(Qt::red,this,tr("颜色对话框"),QColorDialog::ShowAlphaChannel);  //和下面等效



    QColorDialog dialog(Qt::red,this);                 //创建对象
    dialog.setOption(QColorDialog::ShowAlphaChannel); //显示alpha选项
    dialog.exec();                                    //模态方式运行对话框
    QColor color = dialog.currentColor();             //获取当前颜色
    qDebug()<<"color:"<<color;                        //输出当前颜色信息
}


void MyWidget::on_pushButton_2_clicked()
{
    //ok用于标记是否单击了ok按钮
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    //如果单击了ok，那么让“字体对话框”使用新字体
    //如果单击cancel，那么输出信息
    if(ok) ui->pushButton_3->setFont(font);
    else qDebug()<<tr("没有选择字体！");
}



void MyWidget::on_pushButton_3_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this,tr("问题对话框"),tr("你真的想学Qt吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ret1 == QMessageBox::Yes) qDebug()<<tr("问题！");
    //提示对话框
    int ret2 = QMessageBox::information(this,tr("提示对话框"),tr("这是Qt指南！"),QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug()<<tr("入门指南！");
    //警告对话框
    int ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("程序正在运行，禁止退出！"),QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug()<<tr("警告！");
    //错误对话框
    int ret4 = QMessageBox::critical(this,tr("错误对话框"),tr("发现错误，程序即将退出！"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug()<<tr("出现错误！");
    //关于对话框
    QMessageBox::about(this,tr("关于对话框"),tr("Qt说明书！"));
}

void MyWidget::on_pushButton_4_clicked()
{

}

void MyWidget::on_pushButton_5_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("文件对话框"),"D:",tr("图片文件（*png *jpg）；；（*txt)")); //getOpenFileName以模态方式运行，
                                                                                                             //四个参数：指定父窗口，设置对话框标题，指定默认打开的文件目录,设置文件类型过滤器
    qDebug()<<"filename:"<<filename;

}

void MyWidget::on_pushButton_6_clicked()
{
    bool ok;
    //getText函数：提供一个可输入字符串的对话框，四个参数;指定父窗口，设置窗口标题，设置对话框中的标签显示文本，设置输入字符串显示模式

    //获取字符串
    QString string = QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入用户名："),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)  qDebug()<<"字符串string:"<<string;
    //获取整数
    int value = QInputDialog::getInt(this,tr("输入整数对话框"),tr("请输入100-1000之间的数值"),/*默认值*/100,/*最小值*/-1000,/*最大值*/1000,10,&ok);//10表示使用箭头按钮，数值每次变化10；
    if(ok) qDebug()<<"value:"<<value;
    //获取浮点数
    double value2 = QInputDialog::getDouble(this, tr("输入浮点数对话框"),tr("请输入100-1000之间的数值"),0.00,-1000,1000,/*小数位数*/2,&ok);
    if(ok) qDebug()<<"value2:"<<value2;
    QStringList items;
    items<<tr("条目1")<<("条目2");
    //获取条目
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"), tr("请选择或输入一个条目"),items,/*默认第0个条目*/0,/*设置条目可更改*/true,&ok);
    if(ok) qDebug()<<"item:"<<item;
}

void MyWidget::on_pushButton_7_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"),0,50000,this);
    dialog.setWindowTitle(tr("进度提示框"));                              //设置标题
    dialog.setWindowModality(Qt::WindowModal);                              //将窗口设置为模态
    dialog.show();
    for(int i = 0; i < 50000; i++)                                           //演示复制进度
    {
        dialog.setValue(i);                                                 //设置进度条当前值
        QCoreApplication::processEvents();                                  //避免界面冻结
        if(dialog.wasCanceled())  break;                                    //按下取消按键则中断
    }
    dialog.setValue(50000);                                                  //由于for循环少加一个数，这样才能显示100%
    qDebug()<<tr("复制结束！")<<endl;
}





