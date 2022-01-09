#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "qstring.h"
#include <math.h>

using namespace std;

QImage img1(500,500, QImage::Format_RGB888);
QImage img2(500,500, QImage::Format_RGB888);

struct Point {
    float x,y;
};


QVector<Point> coords;
QVector<Point> output_coords;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img1.fill(qRgb(0,0,0));
    img2.fill(qRgb(0,0,0));

    coords.push_back(Point {100,100});
    coords.push_back(Point {100,400});
    coords.push_back(Point {400,400});
    coords.push_back(Point {100,100});
    DDA_Line(100,100,100,400,true);
    DDA_Line(100,400,400,400,true);
    DDA_Line(400,400,100,100,true);

    ui->label->setPixmap(QPixmap::fromImage(img1));
    ui->label_2->setPixmap(QPixmap::fromImage(img2));
}

float getXmax() {
    float max = 0;
    for (int i =0; i < coords.size(); i++) {
        if (max < coords[i].x) {
            max = coords[i].x;
        }
    }
    return max;
}

float getYmax() {
    float max = 0;
    for (int i =0; i < coords.size(); i++) {
        if (max < coords[i].y) {
            max = coords[i].y;
        }
    }
    return max;
}

float getXmin() {
    float min = coords[0].x;
    for (int i =0; i < coords.size(); i++) {
        if (min > coords[i].x) {
            min = coords[i].x;
        }
    }
    return min;
}

float getYmin() {
    float min = coords[0].y;
    for (int i =0; i < coords.size(); i++) {
        if (min > coords[i].y) {
            min = coords[i].y;
        }
    }
    return min;
}

void MainWindow::DDA_Line(float x1, float y1, float x2, float y2, bool isInput)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float step;
    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }
    else {
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    float x = x1;
    float y = y1;

    for (int i =0; i < step; i++) {
        if (isInput) {
            img1.setPixel(x,y,qRgb(255,255,255));
        }
        else {
            img2.setPixel(x,y,qRgb(255,255,255));
        }

        x+=dx;
        y+=dy;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    string s1 = arg1.toStdString();
    if (s1 == "Scale") {
        ui->label_3->show();
        ui->label_3->setText("Sx : ");
        ui->label_4->show();
        ui->label_4->setText("Sy : ");
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->textEdit->show();
        ui->textEdit_2->show();
    }
    else if (s1 == "Translate") {
        ui->label_3->show();
        ui->label_3->setText("Tx : ");
        ui->label_4->show();
        ui->label_4->setText("Ty : ");
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->textEdit->show();
        ui->textEdit_2->show();
    }
    else if (s1 == "Rotate") {
        ui->label_3->hide();
        ui->label_4->show();
        ui->label_4->setText("Angle : ");
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->textEdit->hide();
        ui->textEdit_2->show();
    }
}


void MainWindow::on_pushButton_clicked()
{
    string s1 = ui->comboBox->currentText().toStdString();
    if (s1 == "Scale") {
        float scalex = ui->textEdit->toPlainText().toFloat();
        float scaley = ui->textEdit_2->toPlainText().toFloat();
        for (int i = 0; i < coords.size(); i++) {
            float x = coords[i].x * scalex;
            float y = coords[i].y * scaley;
            output_coords.push_back(Point {x,y});
        }
        for (int i = 0; i < output_coords.size() - 1; i++) {
            DDA_Line(output_coords[i].x, output_coords[i].y, output_coords[i+1].x, output_coords[i+1].y, false);
        }
    }
    else if (s1 == "Translate") {
        float tx = ui->textEdit->toPlainText().toFloat();
        float ty = ui->textEdit_2->toPlainText().toFloat();
        for (int i = 0; i < coords.size(); i++) {
            float x = coords[i].x + tx;
            float y = coords[i].y + ty;
            output_coords.push_back(Point {x,y});
        }
        for (int i = 0; i < output_coords.size() - 1; i++) {
            DDA_Line(output_coords[i].x, output_coords[i].y, output_coords[i+1].x, output_coords[i+1].y, false);
        }
    }
    else if (s1 == "Rotate") {
        float angle = ui->textEdit_2->toPlainText().toFloat() * (M_PI / 180.0);
        float xmax = getXmax();
        float ymax = getYmax();
        float xmin = getXmin();
        float ymin = getYmin();
        float xtran = (xmax + xmin) / 2;
        float ytran = (ymax + ymin) / 2;
        for (int i = 0; i < coords.size(); i++) {
            float x = (coords[i].x - xtran)*cos(angle) - (coords[i].y - ytran)*sin(angle);
            float y = (coords[i].x - xtran)*sin(angle) + (coords[i].y - ytran)*cos(angle);
            output_coords.push_back(Point {x,y});
        }
        for (int i = 0; i < output_coords.size() - 1; i++) {
            DDA_Line(output_coords[i].x + xtran, output_coords[i].y + ytran, output_coords[i+1].x + xtran, output_coords[i+1].y + ytran, false);
        }
    }
    ui->label_2->setPixmap(QPixmap::fromImage(img2));
    output_coords.clear();
}
