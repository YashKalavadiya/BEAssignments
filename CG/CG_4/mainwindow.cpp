#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
#include "iostream"
#define PI acos(-1)
QImage img(900,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count1=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()        //DDA
{
    int x1=ui->textEdit->toPlainText().toFloat();
    int y1=ui->textEdit_2->toPlainText().toFloat();
    int x2=ui->textEdit_3->toPlainText().toFloat();
    int y2=ui->textEdit_4->toPlainText().toFloat();

    coo[count][0]=x1;
    coo[count][1]=y1;
    coo[count][2]=x2;
    coo[count][3]=y2;

    lenarr[count]=sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    count++;
    count1++;

    DDA(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()      //Scale
{
    float scl=ui->textEdit_5->toPlainText().toFloat();
    scale(scl);
}


void MainWindow::on_pushButton_3_clicked()      //Translate
{
    int tx=ui->textEdit_6->toPlainText().toInt();
    int ty=ui->textEdit_7->toPlainText().toInt();
    translate(tx,ty);
}


void MainWindow::on_pushButton_4_clicked()      //Rotation
{
    float angle=ui->textEdit_8->toPlainText().toFloat();
    rotate(angle);
}

void MainWindow::DDA(float x1, float y1, float x2, float y2)  //Digital Differential Analyzer
{
    float xi,yi,step;
    dx=x2-x1;
    dy=y2-y1;

    step=abs(dx)>abs(dy)?abs(dx):abs(dy);   //setting steps i.e how much x1 and y1 should incremented

    xi=dx/step;             //assigning values by how much point should incremented
    yi=dy/step;             //for both x and y with help of step

    i=1;
    float x=x1;
    float y=y1;

    while(i<=step)      //setting pixels on screen with help of steps calculated above
    {

        x=x+xi;
        y=y+yi;
        img.setPixel(x,y,qRgb(255,255,255));
        i++;
    }
}

void MainWindow::scale(float s)
{
    for (int x=0;x<900;++x)
    {
        for (int y=0;y<400;++y)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }

    }

    for (int j=0;j<=count;j++)
    {

        coo[j][0]=coo[j][0]*s;
        coo[j][1]=coo[j][1]*s;
        coo[j][2]=coo[j][2]*s;
        coo[j][3]=coo[j][3]*s;
    }
    for (int j=0;j<count;j++)
    {
        DDA(coo[j][0],coo[j][1],coo[j][2],coo[j][3]);
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::translate(int tx,int ty)
{
    for(int x=0;x<900;++x)
    {
        for (int y=0;y<400;++y)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }
    }
    for (int j=0;j<count;j++)
    {
        coo[j][0]=coo[j][0]+tx;
        coo[j][1]=coo[j][1]+ty;
        coo[j][2]=coo[j][2]+tx;
        coo[j][3]=coo[j][3]+ty;
//        for (i=0;i<4;i++)
//        {
//            coo[j][0]=coo[j][0]+tx;
//            coo[j][1]=coo[j][1]+ty;
//            coo[j][2]=coo[j][2]+tx;
//            coo[j][4]=coo[j][3]+ty;
//        }
    }

    for (int j=0;j<count;j++)
    {
        DDA(coo[j][0],coo[j][1],coo[j][2],coo[j][3]);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::rotate(float angle)
{
    float x[10],y[10];
    float c = cos(angle *PI/180);
    float s = sin(angle *PI/180);


    for (int x=0;x<900;++x)
    {
        for(int y=0;y<400;++y)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }
    }
    int i=0;
    x[0] = floor(coo[0][0] * c + coo[0][1] * s);
    y[0] = floor(-coo[0][0] * s + coo[0][1] * c);
    x[1] = floor(coo[0][2] * c + coo[0][3] * s);
    y[1] = floor(-coo[0][2] * s + coo[0][3] * c);
    for(i=1;i<count-1;i++){
        x[i+1] = floor(coo[i][2] * c + coo[i][3] * s);
        y[i+1] = floor(-coo[i][2] * s + coo[i][3] * c);
    }

    for(i=0;i<count-1;i++){
        DDA(x[i]+300,y[i]+250,x[i+1]+300,y[i+1]+250);
//        DDA(abs(x[i]),abs(y[i]),abs(x[i+1]),abs(y[i+1]));
    }
    DDA(x[count-1]+300,y[count-1]+250,x[0]+300,y[0]+250);
//    DDA(abs(x[count-1]),abs(y[count-1]),abs(x[0]),abs(y[0]));

    ui->label->setPixmap(QPixmap::fromImage(img));
}
