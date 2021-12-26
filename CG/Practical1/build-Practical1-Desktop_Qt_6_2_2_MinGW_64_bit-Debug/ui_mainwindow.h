/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *y1;
    QTextEdit *y2;
    QLabel *label_4;
    QPushButton *helloBtn;
    QLabel *label_2;
    QPushButton *reset;
    QTextEdit *r;
    QTextEdit *x2;
    QTextEdit *x1;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label;
    QPushButton *drawCircle;
    QLabel *labelx1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        y1 = new QTextEdit(centralwidget);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setGeometry(QRect(690, 60, 104, 41));
        y2 = new QTextEdit(centralwidget);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setGeometry(QRect(690, 160, 104, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(660, 120, 16, 19));
        helloBtn = new QPushButton(centralwidget);
        helloBtn->setObjectName(QString::fromUtf8("helloBtn"));
        helloBtn->setGeometry(QRect(690, 220, 103, 36));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 70, 16, 19));
        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(700, 290, 83, 29));
        r = new QTextEdit(centralwidget);
        r->setObjectName(QString::fromUtf8("r"));
        r->setGeometry(QRect(690, 360, 104, 41));
        x2 = new QTextEdit(centralwidget);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(690, 110, 104, 41));
        x1 = new QTextEdit(centralwidget);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(690, 10, 104, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 170, 16, 19));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(640, 370, 41, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 601, 501));
        drawCircle = new QPushButton(centralwidget);
        drawCircle->setObjectName(QString::fromUtf8("drawCircle"));
        drawCircle->setGeometry(QRect(690, 430, 103, 36));
        labelx1 = new QLabel(centralwidget);
        labelx1->setObjectName(QString::fromUtf8("labelx1"));
        labelx1->setGeometry(QRect(660, 20, 16, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        helloBtn->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y1", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "radius", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Coordinates", nullptr));
        drawCircle->setText(QCoreApplication::translate("MainWindow", "Draw Circle", nullptr));
        labelx1->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
