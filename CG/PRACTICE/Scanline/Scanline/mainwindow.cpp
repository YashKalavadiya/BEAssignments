#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
#include "QColorDialog"
#include "QVector"
#include "algorithm"
#include "QMessageBox"
#include "iostream"
QImage img(700, 700, QImage::Format_RGB888);
QRgb rgb(qRgb(255, 255, 255));

struct line {
    int startx, starty, endx, endy;
};

QVector<line> lines;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dy, dx;
    dx = x2 - x1;
    dy = y2 - y1;
    float step, xinc, yinc;
    if(abs(dx) >= abs(dy)) {
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    xinc = dx/step;
    yinc = dy/step;

    float x = x1, y = y1;

    int i = 1;
    while(i <= step) {
        img.setPixel(x, y, rgb);
        x += xinc;
        y += yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::scanLine()
{
    std::cout<<"MYLOG asfn";
    int ymin = lines[0].starty;
    int ymax = 0;



    for(int i = 0; i < lines.size(); i++) {
        if(lines[i].starty > ymax){
            ymax = lines[i].starty;
        }
        if(lines[i].starty < ymin) {
            ymin = lines[i].starty;
        }
    }

    int intersectionPoints[10];
    float *m = new float[lines.size()];

    for (int i = 0; i < lines.size(); i++) {
        float dy, dx;
        dy = lines[i].endy - lines[i].starty;
        dx = lines[i].endx - lines[i].startx;
        if(dy == 0) {
            m[i] = 1.0;
        }
        if(dx == 0){
            m[i] = 0.0;
        }
        if((dy != 0.0) && (dx != 0.0)) {
            m[i] = dx/dy;
        }
    }

    for (int y = ymin+1; y < ymax; y++) {
        int k = 0;
        for(int j = 0; j < lines.size(); j++) {
            if(((lines[j].starty <= y) && (lines[j].endy > y)) || ((lines[j].starty > y) && (lines[j].endy <= y))){

                intersectionPoints[k] = int(lines[j].startx + (m[j] * (y-lines[j].starty)));
                std::cout<<intersectionPoints[k]<<std::endl;
                k++;
            }
        }

//        std::sort(intersectionPoints, &intersectionPoints[k-1]);

        for(int j = 0; j < k-1; j++){
            for(int x = 0; x < k-j-1; x++){
                if(intersectionPoints[x] > intersectionPoints[x+1]){
                    int temp = intersectionPoints[x];
                    intersectionPoints[x] = intersectionPoints[x+1];
                    intersectionPoints[x+1] = temp;
                }
            }
        }

        for(int j = 0; j <= k-2; j+=2) {
            dda(intersectionPoints[j], y, intersectionPoints[j+1], y);
        }
    }
//    delete [] m;
}


void MainWindow::on_pushButton_clicked()
{
    float x1, y1, x2, y2;
    x1 = ui->x1->toPlainText().toFloat();
    y1 = ui->y1->toPlainText().toFloat();
    x2 = ui->x2->toPlainText().toFloat();
    y2 = ui->y2->toPlainText().toFloat();

    line l;
    l.startx = x1;
    l.starty = y1;
    l.endx = x2;
    l.endy = y2;
    lines.push_back(l);
    dda(x1, y1, x2, y2);
}


void MainWindow::on_pushButton_2_clicked()
{
    QRgb color(QColorDialog::getColor().rgb());

    rgb = color;
}


void MainWindow::on_pushButton_3_clicked()
{
    scanLine();
    if((lines[0].startx == lines[lines.size()-1].endx) && (lines[0].starty == lines[lines.size()-1].endy)) {
        std::cout<<"MYLOG"<<std::endl;

    }
    else {
        QMessageBox message;

        message.information(0, "Error!!", "Polygon is not closed");
    }
}

