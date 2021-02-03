#ifndef WIDGET_H
#define WIDGET_H

#include "FileMd5.h"
#include <QWidget>
#include<QPoint>
#include<QThread>
#include<QHash>
#include<QMap>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

        //定义鼠标事件
        void mouseMoveEvent(QMouseEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);

 signals:
        void checkDumplate(const QString &path);

private slots:
    void on_Minbutton_clicked();

    void on_Maxbutton_clicked();

    void on_Closebutton_clicked();
    
    void on_Filebutton_clicked();

    void on_getfile_clicked();

    void on_getDrumplate(const QHash<QByteArray, QStringList> &dumplates);
    void on_progress(int current, int total);

private:
    Ui::Widget *ui;
     QPoint z;
    FileMd5 md5;
    QThread thread;

};

#endif // WIDGET_H
