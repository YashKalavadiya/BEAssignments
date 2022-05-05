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
    QTextEdit *Ymin;
    QLabel *label_3;
    QTextEdit *Ymax;
    QTextEdit *Xmin;
    QLabel *labelx1;
    QLabel *label_4;
    QTextEdit *Xmax;
    QPushButton *drawWin;
    QLabel *label_2;
    QLabel *label;
    QTextEdit *x2;
    QLabel *label_5;
    QTextEdit *y2;
    QTextEdit *x1;
    QLabel *labelx1_2;
    QLabel *label_6;
    QTextEdit *y1;
    QPushButton *helloBtn;
    QLabel *label_7;
    QPushButton *clip;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Ymin = new QTextEdit(centralwidget);
        Ymin->setObjectName(QString::fromUtf8("Ymin"));
        Ymin->setGeometry(QRect(690, 100, 104, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(640, 160, 41, 20));
        Ymax = new QTextEdit(centralwidget);
        Ymax->setObjectName(QString::fromUtf8("Ymax"));
        Ymax->setGeometry(QRect(690, 150, 104, 41));
        Xmin = new QTextEdit(centralwidget);
        Xmin->setObjectName(QString::fromUtf8("Xmin"));
        Xmin->setGeometry(QRect(690, 0, 104, 41));
        labelx1 = new QLabel(centralwidget);
        labelx1->setObjectName(QString::fromUtf8("labelx1"));
        labelx1->setGeometry(QRect(640, 10, 41, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(645, 110, 31, 20));
        Xmax = new QTextEdit(centralwidget);
        Xmax->setObjectName(QString::fromUtf8("Xmax"));
        Xmax->setGeometry(QRect(690, 50, 104, 41));
        drawWin = new QPushButton(centralwidget);
        drawWin->setObjectName(QString::fromUtf8("drawWin"));
        drawWin->setGeometry(QRect(690, 210, 103, 36));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(635, 60, 41, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 601, 471));
        x2 = new QTextEdit(centralwidget);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(690, 370, 104, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 430, 16, 19));
        y2 = new QTextEdit(centralwidget);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setGeometry(QRect(690, 420, 104, 41));
        x1 = new QTextEdit(centralwidget);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(690, 270, 104, 41));
        labelx1_2 = new QLabel(centralwidget);
        labelx1_2->setObjectName(QString::fromUtf8("labelx1_2"));
        labelx1_2->setGeometry(QRect(660, 280, 16, 19));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(660, 380, 16, 19));
        y1 = new QTextEdit(centralwidget);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setGeometry(QRect(690, 320, 104, 41));
        helloBtn = new QPushButton(centralwidget);
        helloBtn->setObjectName(QString::fromUtf8("helloBtn"));
        helloBtn->setGeometry(QRect(690, 480, 103, 36));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(660, 330, 16, 19));
        clip = new QPushButton(centralwidget);
        clip->setObjectName(QString::fromUtf8("clip"));
        clip->setGeometry(QRect(270, 500, 191, 36));
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
        label_3->setText(QCoreApplication::translate("MainWindow", "Ymax", nullptr));
        labelx1->setText(QCoreApplication::translate("MainWindow", "Xmin", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ymin", nullptr));
        drawWin->setText(QCoreApplication::translate("MainWindow", "Draw Win", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Xmax", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Coordinates", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y2", nullptr));
        labelx1_2->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        helloBtn->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y1", nullptr));
        clip->setText(QCoreApplication::translate("MainWindow", "Clip Lines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
