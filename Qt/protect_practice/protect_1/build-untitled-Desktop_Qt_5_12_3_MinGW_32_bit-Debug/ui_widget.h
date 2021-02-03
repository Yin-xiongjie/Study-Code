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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *MinBtn;
    QPushButton *MaxBtn;
    QPushButton *pushButton_3;
    QFrame *frame;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(703, 476);
        shadowWidget = new QWidget(Widget);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setGeometry(QRect(0, -10, 701, 481));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shadowWidget->sizePolicy().hasHeightForWidth());
        shadowWidget->setSizePolicy(sizePolicy);
        shadowWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 255, 243);"));
        verticalLayout = new QVBoxLayout(shadowWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(shadowWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);\n"
"font: 20pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        MinBtn = new QPushButton(shadowWidget);
        MinBtn->setObjectName(QString::fromUtf8("MinBtn"));
        MinBtn->setMinimumSize(QSize(50, 50));
        MinBtn->setMaximumSize(QSize(50, 50));
        MinBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 255, 177);"));

        horizontalLayout->addWidget(MinBtn);

        MaxBtn = new QPushButton(shadowWidget);
        MaxBtn->setObjectName(QString::fromUtf8("MaxBtn"));
        MaxBtn->setMinimumSize(QSize(50, 50));
        MaxBtn->setMaximumSize(QSize(50, 50));
        MaxBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 255, 177);"));

        horizontalLayout->addWidget(MaxBtn);

        pushButton_3 = new QPushButton(shadowWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 255, 177);"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        frame = new QFrame(shadowWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\345\260\217\347\225\214\351\235\242", nullptr));
        MinBtn->setText(QString());
        MaxBtn->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
