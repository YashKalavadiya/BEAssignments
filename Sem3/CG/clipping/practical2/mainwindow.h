#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct lineCoords {
public:
    float x1, y1, x2, y2;
};

class line {
public:
    friend class MainWindow;
    void DDALine(float,float,float,float, Ui::MainWindow*, bool);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float xmin, ymin, xmax, ymax;
    line l;
    QVector<lineCoords> lines;
    friend class line;

private slots:
    void on_drawWin_clicked();
    void on_helloBtn_clicked();

    void on_clip_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
