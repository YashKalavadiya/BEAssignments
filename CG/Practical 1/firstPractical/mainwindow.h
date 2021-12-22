#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    int x1 = 400;
    int y1 = 300;
    int x2 = 900;
    int y2 = 1000;

private slots:
    void on_helloBtn_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
