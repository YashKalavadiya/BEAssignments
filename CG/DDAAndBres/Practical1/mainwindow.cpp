#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "string.h"
#include "iostream"
#include "QImage"
using namespace std;

QImage img(500,500, QImage :: Format_RGB888);

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

void MainWindow::DDAAlgo(int x1, int y1, int x2, int y2){
 float dx, dy, step, i, x , y;
     float Xinc, Yinc;
     dx = x2 - x1;
     dy = y2-y1;
     if(abs(dx) >= abs (dy))
     {
         step = abs(dx);
     }
     else
     {
         step = abs(dy);
     }

     Xinc = dx/step;
     Yinc=dy/step;

     i = 0;
     x = x1;
     y = y1;
     while(i <= step)
     {

         img.setPixel(x,y, qRgb(255,255,255));
         x = x + Xinc;
         y = y + Yinc;
         MainWindow::xPoints.append(x);
         MainWindow::yPoints.append(y);
         i++;
     }
}

void MainWindow::BresenhamCircleAlgo(int r, int x1, int y1) {
    float d = 3 - 2*r;
    int x = 0, y = r;

    while(x <= y){
    img.setPixel(x1+x,y1+y,qRgb(255,255,255));
    img.setPixel(x1-x,y1+y,qRgb(255,255,255));
    img.setPixel(x1+x,y1-y,qRgb(255,255,255));
    img.setPixel(x1-x,y1-y,qRgb(255,255,255));
    img.setPixel(x1+y,y1+x,qRgb(255,255,255));
    img.setPixel(x1+y,y1-x,qRgb(255,255,255));
    img.setPixel(x1-y,y1+x,qRgb(255,255,255));
    img.setPixel(x1-y,y1-x,qRgb(255,255,255));
    x += 1;
    if(d<0) {
        d = d + (4*x) + 6;
    }
    else{
        d = d + 4*(x - y) + 10;
        y -= 1;
    }
    }

}

//250,250,100 for outer circle
//250,250,50 for inner circle
//250,150,336,300 
//336,300,163,300
//163,300,250,150

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen linePen(Qt::red);

    linePen.setWidth(1);
    painter.setPen(linePen);

    if(!MainWindow::xPoints.empty() && !MainWindow::yPoints.empty())
    for(int i = 0; i < MainWindow::xPoints.size(); i++) {
        img.setPixel(MainWindow::xPoints[i], MainWindow::yPoints[i], qRgb(255,255,255));
        cout<<"\n"<<MainWindow::xPoints[i]<<"\n"<<MainWindow::yPoints[i]<<endl;
    }
}
void MainWindow::on_helloBtn_clicked(){
    MainWindow::xPoints.clear();
    MainWindow::yPoints.clear();
    QString x1 = ui->x1->toPlainText();
    QString x2 = ui->x2->toPlainText();
    QString y1 = ui->y1->toPlainText();
    QString y2 = ui->y2->toPlainText();
    MainWindow::x1 = std::stoi(x1.toStdString());
    MainWindow::x2 = std::stoi(x2.toStdString());
    MainWindow::y1 = std::stoi(y1.toStdString());
    MainWindow::y2 = std::stoi(y2.toStdString());


    MainWindow::DDAAlgo(MainWindow::x1, MainWindow::y1, MainWindow::x2, MainWindow::y2);

    ui->label->setPixmap(QPixmap :: fromImage(img));
//    update();
}

void MainWindow::on_drawCircle_clicked() {
    MainWindow::BresenhamCircleAlgo(ui->r->toPlainText().toInt(), ui->x1->toPlainText().toInt(), ui->y1->toPlainText().toInt());
    ui->label->setPixmap(QPixmap :: fromImage(img));
}

void MainWindow::on_reset_clicked(){
    MainWindow::xPoints.clear();
    MainWindow::yPoints.clear();
    img = QImage(500,500, QImage :: Format_RGB888);
    ui->label->setPixmap(QPixmap :: fromImage(img));
    cout<<"Pressed";
    update();
}
