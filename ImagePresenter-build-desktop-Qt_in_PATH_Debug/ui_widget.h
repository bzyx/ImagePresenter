/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu 22. Dec 20:26:33 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btn_help;
    QGraphicsView *gView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QPushButton *btn_changeImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(376, 364);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_help = new QPushButton(Widget);
        btn_help->setObjectName(QString::fromUtf8("btn_help"));

        verticalLayout->addWidget(btn_help);

        gView = new QGraphicsView(Widget);
        gView->setObjectName(QString::fromUtf8("gView"));

        verticalLayout->addWidget(gView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_prev = new QPushButton(Widget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));

        horizontalLayout->addWidget(btn_prev);

        btn_next = new QPushButton(Widget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));

        horizontalLayout->addWidget(btn_next);


        verticalLayout->addLayout(horizontalLayout);

        btn_changeImage = new QPushButton(Widget);
        btn_changeImage->setObjectName(QString::fromUtf8("btn_changeImage"));

        verticalLayout->addWidget(btn_changeImage);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "ImagePresenter", 0, QApplication::UnicodeUTF8));
        btn_help->setText(QApplication::translate("Widget", "Pomoc", 0, QApplication::UnicodeUTF8));
        btn_prev->setText(QApplication::translate("Widget", "Poprzedni", 0, QApplication::UnicodeUTF8));
        btn_next->setText(QApplication::translate("Widget", "Nast\304\231pny", 0, QApplication::UnicodeUTF8));
        btn_changeImage->setText(QApplication::translate("Widget", "Wybierz obraz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
