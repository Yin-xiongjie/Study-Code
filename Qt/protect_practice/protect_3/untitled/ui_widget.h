/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QPushButton *Filebutton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *Minbutton;
    QPushButton *Maxbutton;
    QPushButton *Closebutton;
    QPushButton *getfile;
    QProgressBar *progressBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(589, 512);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 25, 561, 451));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 252, 196);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Filebutton = new QPushButton(frame);
        Filebutton->setObjectName(QString::fromUtf8("Filebutton"));
        Filebutton->setGeometry(QRect(120, 190, 110, 30));
        Filebutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:1px solid blue;\n"
"border-radius:5px;\n"
"background-color: rgb(188, 247, 255);\n"
"color:#fff;\n"
"font: 14pt \351\232\266\344\271\246;\n"
"}\n"
"QPushButton:hover{\n"
"border:1px solid blue;\n"
"border-radius:5px;\n"
"	background-color: rgb(165, 234, 255);\n"
"color:#fff;\n"
"font: 14pt \351\232\266\344\271\246;\n"
"}"));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 531, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 16pt \"\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(label);

        Minbutton = new QPushButton(horizontalLayoutWidget);
        Minbutton->setObjectName(QString::fromUtf8("Minbutton"));
        Minbutton->setMinimumSize(QSize(30, 30));
        Minbutton->setMaximumSize(QSize(30, 30));
        Minbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image:url(:/new/prefix1/\347\274\251\345\260\217);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/new/prefix1/\347\274\251\345\260\217.hover);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/new/prefix1/\347\274\251\345\260\217.hover);\n"
"border:none;\n"
"}"));

        horizontalLayout->addWidget(Minbutton);

        Maxbutton = new QPushButton(horizontalLayoutWidget);
        Maxbutton->setObjectName(QString::fromUtf8("Maxbutton"));
        Maxbutton->setMinimumSize(QSize(30, 30));
        Maxbutton->setMaximumSize(QSize(30, 30));
        Maxbutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/new/prefix1/\346\224\276\345\244\247);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/new/prefix1/\346\224\276\345\244\247.hover);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/new/prefix1/\346\224\276\345\244\247.hover);\n"
"border:none;\n"
"}"));

        horizontalLayout->addWidget(Maxbutton);

        Closebutton = new QPushButton(horizontalLayoutWidget);
        Closebutton->setObjectName(QString::fromUtf8("Closebutton"));
        Closebutton->setMinimumSize(QSize(30, 30));
        Closebutton->setMaximumSize(QSize(30, 30));
        Closebutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/new/prefix1/\345\205\263\351\227\255);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/new/prefix1/\345\205\263\351\227\255.hover);\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/new/prefix1/\345\205\263\351\227\255.hover);\n"
"border:none;\n"
"}"));

        horizontalLayout->addWidget(Closebutton);

        getfile = new QPushButton(frame);
        getfile->setObjectName(QString::fromUtf8("getfile"));
        getfile->setGeometry(QRect(340, 190, 111, 31));
        getfile->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:1px solid blue;\n"
"border-radius:5px;\n"
"background-color: rgb(188, 247, 255);\n"
"color:#fff;\n"
"font: 14pt \351\232\266\344\271\246;\n"
"}\n"
"QPushButton:hover{\n"
"border:1px solid blue;\n"
"border-radius:5px;\n"
"	background-color: rgb(165, 234, 255);\n"
"color:#fff;\n"
"font: 14pt \351\232\266\344\271\246;\n"
"}"));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(120, 270, 341, 23));
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(0);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        Filebutton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\346\211\223\345\274\200", nullptr));
        Minbutton->setText(QString());
        Maxbutton->setText(QString());
        Closebutton->setText(QString());
        getfile->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
