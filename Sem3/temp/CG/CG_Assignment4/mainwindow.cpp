#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <math.h>
#include <QTime>
#define height 600
#define width 800
using namespace std;

int vert,i,y,xi[20],j,temp,k;        //defining all the variables that will be used in the scan line algorithm
int a[20][2];                        //defining an array in which we will store all the vertex
float slope[20],dx,dy;              //defining array for storing the slopes of lines
bool flag=true;                     //boolean to check if the the plygon is closed or not

QImage img(width, height, QImage::Format_RGB888); //defining screen and RGB format
QRgb rgb(qRgb(255,255,255));                       //setting base color to white

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //we will clear the screen at once and set all the pixels to black as soon as the code is run. This enhances the GUI
    for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));      //setting all the pixels on the screen to black (0,0,0)
            }
        }
     ui->label->setPixmap(QPixmap::fromImage(img));
     vert=0;                                            //Initializing the value of no. of vertices to 0
     flag=true;                                        //setting polygon to open
}

MainWindow::~MainWindow()
{
    delete ui;
}

void delay( int millisecondsToWait )                   //delay function to visualize scanline fill
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void line::DDALine(float x1, float y1, float x2, float y2, Ui::MainWindow *ui, int delay_time=0)
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
        img.setPixel(x, y, rgb);
        i++;
        ui->label->setPixmap(QPixmap::fromImage(img));
        delay(delay_time);                  //delaying the line print
    }


}

void Fill::ScanLineFill(Ui::MainWindow *ui)         //function for scanlinefill
{
    for(i=0;i<vert-1;i++)
                {
                    dy = a[i+1][1] - a[i][1];
                    dx = a[i+1][0] - a[i][0];
                    if(dy == 0.0)
                    {
                        slope[i] = 1.0;
                    }
                    if(dx == 0.0)
                    {
                        slope[i] = 0.0;
                    }
                    if((dy != 0.0) && (dx != 0.0))
                    {
                        slope[i] = dx / dy;
                    }
                }


                for(int y=0;y<height;y++)
                {
                    k = 0;

                    // code to generate the scan line table
                    for(i=0;i<vert-1;i++)
                    {
                        if(((a[i][1]<=y) && (a[i+1][1]>y)) || ((a[i][1]>y) && (a[i+1][1]<=y)))
                        {
                            xi[k] = int(a[i][0] + (slope[i]*(y-a[i][1])));
                            k++;
                        }
                    }

                    // Code for bubble sort
//                    for(j=0;j<k-1;j++)
//                    {
//                        for(i=0;i<k-j-1;i++)
//                        {
//                            if(xi[i]>xi[i+1])
//                            {
//                                temp = xi[i];
//                                xi[i] = xi[i+1];
//                                xi[i+1] = temp;
//                            }
//                        }
//                    }

                    // code for printing the final line
                    for(i=0;i<k;i+=2)
                    {
                        DDALine(xi[i],y,xi[i+1]+1,y, ui,3);     //filling the line with delay of 3 milliseconds
                    }
                }
}



void MainWindow::on_pushButton_clicked()            //function to select custom color
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw
    rgb = color;
}


void MainWindow::on_pushButton_3_clicked()          //function to clear the screen
{
    QMessageBox message;
    message.information(0,"Screen has been cleared.","Please draw new polygon");
    for (int x = 0; x < width; ++x)
        {                                              //iterating through every pixel on the screen
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));      //setting all the pixels on the screen to black (0,0,0)
            }
        }
        ui->textEdit->clear();                  //clearing textbox1
        ui->textEdit_2->clear();                //clearing textbox2
        ui->textEdit_3->clear();                //clearing textbox3
        ui->textEdit_4->clear();                //clearing textbox4
        ui->label->setPixmap(QPixmap::fromImage(img));
        for (int q =0; q<=vert;q++)
        {
            for (int b=0;b<2;b++)
            {
                a[q][b]=0;              //resetting every element of the array so that all the vertices are cleared
            }
        }
        vert=0;                         //setting number of vertices to 0
        flag=true;                      //resetting plygon to open
}

void MainWindow::on_pushButton_4_clicked()      //function to draw polygon line
{
    QMessageBox message;            //object for messagebox
    if(ui->textEdit->toPlainText().isEmpty()||ui->textEdit_2->toPlainText().isEmpty()||ui->textEdit_3->toPlainText().isEmpty()||ui->textEdit_4->toPlainText().isEmpty())
    {
        message.information(0,"Warning!","Fields cannot be left empty!");     //EH for empty inputs
    }

    else
    {
        //getting inputs from respective textboxes
        int x1 = ui->textEdit->toPlainText().toInt();           //getting value of x1
        int y1 = ui->textEdit_2->toPlainText().toInt();         //getting value of y1

        int x2 = ui->textEdit_3->toPlainText().toInt();         //getting value of x2
        int y2 = ui->textEdit_4->toPlainText().toInt();         //getting value of y2

        if(flag)                                                //checking if polygon is open or not
        {
            a[vert][0] = x1;
            a[vert][1] = y1;
            vert++;
            flag=false;
        }

        a[vert][0] = x2;        //storing x coordinate of the vertex
        a[vert][1] = y2;        //storing y coordinate of the vertex
        vert++;                 //incrementing the number of vertices present in total

        obj.DDALine(x1,y1,x2,y2,ui,0);               //drawing the line on the screen
    }

}


void MainWindow::on_pushButton_2_clicked()          //function for filling the polygon
{
    QMessageBox message;
    if(a[0][0]==a[vert-1][0] && a[0][1]==a[vert-1][1])      //checking if the polygon is closed or not
    {
        obj.ScanLineFill(ui);                               //calling function for scan fill
    }
    else
    {
        message.information(0,"Warning!","The polygon has not been closed properly! Please check the coordinates!");   //EH for open polygon
    }
}

