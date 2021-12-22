#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

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
    void DDAAlgo(int x1,int y1,int x2,int y2);
    int x1;
    int y1;
    int x2;
    int y2;
    QVector<int> xPoints;
    QVector<int> yPoints;
    int r, p, q;
    void BresenhamCircleAlgo(int r,int p,int q);

private slots:
    void on_helloBtn_clicked();
    void on_reset_clicked();
    void on_drawCircle_clicked();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
