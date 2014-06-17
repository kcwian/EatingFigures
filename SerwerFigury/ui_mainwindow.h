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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditServer;
    QComboBox *comboBox;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QLabel *labelIP;
    QLabel *labelPort;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(225, 253);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 60, 111, 136));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        lineEditServer = new QLineEdit(verticalLayoutWidget);
        lineEditServer->setObjectName(QStringLiteral("lineEditServer"));
        lineEditServer->setReadOnly(true);

        verticalLayout->addWidget(lineEditServer);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        pushButtonStart = new QPushButton(verticalLayoutWidget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        verticalLayout->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(verticalLayoutWidget);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));

        verticalLayout->addWidget(pushButtonStop);

        labelIP = new QLabel(centralWidget);
        labelIP->setObjectName(QStringLiteral("labelIP"));
        labelIP->setGeometry(QRect(20, 10, 107, 27));
        QFont font;
        font.setPointSize(10);
        labelIP->setFont(font);
        labelIP->setLayoutDirection(Qt::RightToLeft);
        labelIP->setScaledContents(false);
        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setGeometry(QRect(130, 10, 109, 28));
        labelPort->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Serwer", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Poziom 0", 0)
         << QApplication::translate("MainWindow", "Poziom 1", 0)
         << QApplication::translate("MainWindow", "Poziom 2", 0)
         << QApplication::translate("MainWindow", "Poziom 3", 0)
         << QApplication::translate("MainWindow", "Poziom 4", 0)
         << QApplication::translate("MainWindow", "Poziom 5", 0)
         << QApplication::translate("MainWindow", "Poziom 6", 0)
         << QApplication::translate("MainWindow", "Poziom 7", 0)
         << QApplication::translate("MainWindow", "Poziom 8", 0)
         << QApplication::translate("MainWindow", "Poziom 9", 0)
        );
        pushButtonStart->setText(QApplication::translate("MainWindow", "START", 0));
        pushButtonStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        labelIP->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        labelPort->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
