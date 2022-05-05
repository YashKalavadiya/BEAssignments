#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class line
{
public:
    friend class MainWindow;
    void DDALine(float,float,float,float, Ui::MainWindow*,int);
};

class Fill: public line
{
    friend class MainWindow;
public:
    void ScanLineFill(Ui::MainWindow*);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Fill obj;
    friend class line;
    friend class Fill;



private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
