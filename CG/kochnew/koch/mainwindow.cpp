#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(500,500,QImage::Format_RGB888);
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

void MainWindow::koch(int it,int x1,int y1,int x5,int y5)
{
int x2,y2,x3,y3,x4,y4;
int dx,dy;
if (it==0)
{
dda(x1,y1,x5,y5);
}
else
{
dx=(x5-x1)/3;
dy=(y5-y1)/3;
x2=x1+dx;
y2=y1+dy;
x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
x4=2*dx+x1;
y4=2*dy+y1;
koch(it-1,x1,y1,x2,y2);
koch(it-1,x2,y2,x3,y3);
koch(it-1,x3,y3,x4,y4);
koch(it-1,x4,y4,x5,y5);
}
ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    float dx,dy,step,i,x,y;
    float xincr,yincr;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
    {
        step=abs(dx);
    }
    else
    {
        step=abs(dy);
    }
    xincr=dx/step;
    yincr=dy/step;
    i=0;
    x=x1;
    y=y1;

    while(i<step)
    {
        img.setPixel(x,y,qRgb(255,255,255));
        x+=xincr;
        y+=yincr;
        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{

    int it=ui->textEdit->toPlainText().toInt();


//    koch(it,150,20,20,280);
//    koch(it,280,280,150,20);
//    koch(it,20,280,280,280);
    koch(it,300,250,50,250);
}


void MainWindow::on_pushButton_2_clicked()
{
    for (int x=0;x<500;++x)
    {
        for(int y=0;y<500;++y)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

