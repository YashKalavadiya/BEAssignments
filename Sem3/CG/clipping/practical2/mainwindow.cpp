#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "QVector"
#include "QMessageBox"
#define height 600
#define width 800

using namespace std;


//int lines[20][2];


QImage img(width, height, QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < width; ++x){
        for (int y = 0; y < height; ++y){
            img.setPixel(x, y, qRgb(0, 0, 0));      //setting all the pixels on the screen to black (0,0,0)
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void line::DDALine(float x1, float y1, float x2, float y2, Ui::MainWindow *ui, bool isBlack = false)
{

    float dx = (x2 - x1);
    float dy = (y2 - y1);
    float step;

    //determining the no. of steps for code to run
    if (abs(dx)>=abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    //value by which coordinates will be incremented every iteration
    dx = dx / step;
    dy = dy / step;

    float x = x1, y = y1;
    int i = 1;                  //setting up increment for calculating no. of steps

    //repeating process for no of steps
    while (i <= step)
    {

        x += dx;                //incrementing dx
        y += dy;                //incrementing dy
        if(!isBlack){
         img.setPixel(x, y, rgb);
        }
        else{
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
        i++;
        ui->label->setPixmap(QPixmap::fromImage(img));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawWin_clicked() {
    MainWindow::xmin = ui->Xmin->toPlainText().toFloat();
    MainWindow::ymin= ui->Ymin->toPlainText().toFloat();
    MainWindow::xmax = ui->Xmax->toPlainText().toFloat();
    MainWindow::ymax = ui->Ymax->toPlainText().toFloat();

    MainWindow::l.DDALine(MainWindow::xmin, MainWindow::ymin, MainWindow::xmax, MainWindow::ymin, ui);
    MainWindow::l.DDALine(MainWindow::xmin, MainWindow::ymin, MainWindow::xmin, MainWindow::ymax, ui);
    MainWindow::l.DDALine(MainWindow::xmin, MainWindow::ymax, MainWindow::xmax, MainWindow::ymax, ui);
    MainWindow::l.DDALine(MainWindow::xmax, MainWindow::ymin, MainWindow::xmax, MainWindow::ymax, ui);
}


void MainWindow::on_helloBtn_clicked()
{
    lineCoords l;
    l.x1 = ui->x1->toPlainText().toFloat();
    l.y1 = ui->y1->toPlainText().toFloat();
    l.x2 = ui->x2->toPlainText().toFloat();
    l.y2 = ui->y2->toPlainText().toFloat();

    MainWindow::l.DDALine(l.x1, l.y1, l.x2, l.y2, ui);
    MainWindow::lines.append(l);
}


void MainWindow::on_clip_clicked()
{
    QMessageBox message;
    if(MainWindow::lines.isEmpty()){
        message.information(0, "not allowed!!", "There are no lines to clip");
    }
    else {
        for(int i = 0; i < MainWindow::lines.size(); i++) {
            float xmin = MainWindow::xmin, ymin = MainWindow::ymin, xmax = MainWindow::xmax, ymax = MainWindow::ymax;
            float x1 = MainWindow::lines[i].x1, y1 = MainWindow::lines[i].y1, x2 = MainWindow::lines[i].x2, y2 = MainWindow::lines[i].y2;
            float m = (y2-y1)/(x2-x1);
            string p1 = "0000";
            string p2 = "0000";
            //for p1
            if(x1 < xmin){
                p1[3] = '1';
            }
            else if(x1 > xmax) {
                p1[2] = '1';
            }
            if(y1 < ymin) {
                p1[0] = '1';
            }
            else if(y1 > ymax) {
                p1[1] = '1';
            }
           //for p2
            if(x2 < xmin){
                p2[3] = '1';
            }
            else if(x2 > xmax) {
                p2[2] = '1';
            }
            if(y2 < ymin) {
                p2[0] = '1';
            }
            else if(y2 > ymax) {
                p2[1] = '1';
            }

            string result = "0000";

            for (int j = 0; j < 4; j++) {
                result[j] = char(p1[j] | p2[j]);
            }

            if(result != "0000") {
                for (int j = 0; j < 4; j++) {
                    result[j] = char(p1[j] & p2[j]);
                }
                if(result == "0000") {
                    for(int j = 0; j < 4; j++) {

                        //First Point
                        if(p1[j] == '1') {
                            float x = x1, y = y1;
                            switch(j+1){
                                case 4:                 //Left
                                    y = y1 + m*(xmin - x1);
                                    x = xmin;
                                    break;
                                case 3:                 //Right
                                    y = y1 + m*(xmax - x1);
                                    x = xmax;
                                    break;
                                case 2:                 //Bottom
                                    x = x1 + (ymax - y1)/m;
                                    y = ymax;
                                    break;
                                case 1:                 //TOP
                                    x = x1 + (ymin - y1)/m;
                                    y = ymin;
                                    break;
                            }
                            MainWindow::l.DDALine(x1, y1, x, y, ui, true);
                        }
                        //Second Point
                        if(p2[j] == '1') {
                            float x = x2, y = y2;
                            switch(j+1){
                                case 4:                 //Left
                                    y = y1 + m*(xmin - x1);
                                    x = xmin;
                                    break;
                                case 3:                 //Right
                                    y = y1 + m*(xmax - x1);
                                    x = xmax;
                                    break;
                                case 2:                 //Bottom
                                    x = x1 + (ymax - y1)/m;
                                    y = ymax;
                                    break;
                                case 1:                 //Top
                                    x = x1 + (ymin - y1)/m;
                                    y = ymin;
                                    break;
                            }
                            MainWindow::l.DDALine(x, y, x2, y2, ui, true);
                        }
                    }
                }
                else {
                    MainWindow::l.DDALine(x1, y1, x2, y2, ui, true);
                }
            }
        }
    }
}

