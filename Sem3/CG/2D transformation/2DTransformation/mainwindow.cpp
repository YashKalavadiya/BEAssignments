#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
#define height 600
#define width 900
using namespace std;

QImage img(width, height, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));      //setting all the pixels on the screen to black (0,0,0)
            }
        }
     ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

