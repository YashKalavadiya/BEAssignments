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
#include <QtWidgets/QFrame>
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
    QLabel *label_3;
    QLabel *label;
    QTextEdit *textEdit_3;
    QLabel *label_4;
    QLabel *label_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_5;
    QLabel *label_5;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_2;
    QPushButton *scaling;
    QPushButton *rotation;
    QPushButton *translate;
    QLabel *label_6;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *clear;
    QFrame *line_4;
    QPushButton *TRS;
    QPushButton *SRT;
    QPushButton *RTS;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1294, 628);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0,1,3)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(830, 70, 55, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(650, 70, 55, 16));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(860, 60, 101, 31));
        textEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(830, 150, 55, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 150, 55, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(680, 60, 101, 31));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(1000, 60, 111, 31));
        textEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1040, 100, 55, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(860, 140, 101, 31));
        textEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(680, 140, 101, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        scaling = new QPushButton(centralwidget);
        scaling->setObjectName(QString::fromUtf8("scaling"));
        scaling->setGeometry(QRect(860, 220, 93, 28));
        scaling->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        rotation = new QPushButton(centralwidget);
        rotation->setObjectName(QString::fromUtf8("rotation"));
        rotation->setGeometry(QRect(1010, 220, 93, 28));
        rotation->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        translate = new QPushButton(centralwidget);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setGeometry(QRect(680, 220, 93, 28));
        translate->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 600, 600));
        label_6->setStyleSheet(QString::fromUtf8("border: 1px solid white"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(800, 30, 20, 261));
        line->setStyleSheet(QString::fromUtf8("color: white;"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(970, 30, 20, 261));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(1126, 30, 16, 261));
        line_3->setStyleSheet(QString::fromUtf8(""));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(1170, 120, 93, 28));
        clear->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(640, 290, 601, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        TRS = new QPushButton(centralwidget);
        TRS->setObjectName(QString::fromUtf8("TRS"));
        TRS->setGeometry(QRect(680, 320, 93, 28));
        TRS->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        SRT = new QPushButton(centralwidget);
        SRT->setObjectName(QString::fromUtf8("SRT"));
        SRT->setGeometry(QRect(860, 320, 93, 28));
        SRT->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        RTS = new QPushButton(centralwidget);
        RTS->setObjectName(QString::fromUtf8("RTS"));
        RTS->setGeometry(QRect(1010, 320, 93, 28));
        RTS->setStyleSheet(QString::fromUtf8("background-color: rgb(10,5,105);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 4px;\n"
"color: white;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1294, 21));
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
        label_3->setText(QCoreApplication::translate("MainWindow", "Sx", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Tx", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sy", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ty", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        scaling->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        rotation->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        TRS->setText(QCoreApplication::translate("MainWindow", "TRS", nullptr));
        SRT->setText(QCoreApplication::translate("MainWindow", "SRT", nullptr));
        RTS->setText(QCoreApplication::translate("MainWindow", "RTS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
