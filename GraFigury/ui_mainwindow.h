/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QPushButton *pushButtonPolacz;
    QLabel *labelWynik1;
    QLabel *labelWynik;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(832, 691);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(14, 9, 650, 650));
        widget->setFocusPolicy(Qt::StrongFocus);
        pushButtonPolacz = new QPushButton(centralWidget);
        pushButtonPolacz->setObjectName(QStringLiteral("pushButtonPolacz"));
        pushButtonPolacz->setGeometry(QRect(680, 630, 129, 27));
        labelWynik1 = new QLabel(centralWidget);
        labelWynik1->setObjectName(QStringLiteral("labelWynik1"));
        labelWynik1->setGeometry(QRect(720, 20, 67, 17));
        QFont font;
        font.setPointSize(11);
        labelWynik1->setFont(font);
        labelWynik1->setAlignment(Qt::AlignCenter);
        labelWynik = new QLabel(centralWidget);
        labelWynik->setObjectName(QStringLiteral("labelWynik"));
        labelWynik->setGeometry(QRect(720, 40, 67, 17));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelWynik->setFont(font1);
        labelWynik->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gra", 0));
        pushButtonPolacz->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz", 0));
        labelWynik1->setText(QApplication::translate("MainWindow", "Wynik:", 0));
        labelWynik->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
