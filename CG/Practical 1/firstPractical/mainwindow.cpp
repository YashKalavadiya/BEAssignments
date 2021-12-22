#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "string.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setFont(QFont("Times New Roman", 16, QFont::Bold));

    painter.drawText(QPoint(20,30), "HELLO FROM YASH");

    QPen linePen(Qt::green);

    linePen.setWidth(10);

    painter.setPen(linePen);

//    painter.drawLine(100,200,300,400);
    painter.drawLine(MainWindow::x1,MainWindow::y1,MainWindow::x2,MainWindow::y2);

}

void MainWindow::on_helloBtn_clicked()
{

    QString x1 = ui->x1->toPlainText();
    QString x2 = ui->x2->toPlainText();
    QString y1 = ui->y1->toPlainText();
    QString y2 = ui->y2->toPlainText();
    MainWindow::x1 = std::stoi(x1.toStdString());
    MainWindow::x2 = std::stoi(x2.toStdString());
    MainWindow::y1 = std::stoi(y1.toStdString());
    MainWindow::y2 = std::stoi(y2.toStdString());


    update();
}
