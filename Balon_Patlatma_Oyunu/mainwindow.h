#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>

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

private:
    Ui::MainWindow *ui;
    int x,y1,y2,y3,y4,y5,y6,y7,a,b,c,d,e,f,sayac1 = 0 ,sayac2 = 0, sayac3 = 0, sayac4 = 0 ,sayac5 = 0 , sayac6 = 0, sayac7 = 0;
    int time,count;
    int vurulan_balon_sayisi,kacan_balon_sayisi;
    bool vuruldu1,vuruldu2,vuruldu3,vuruldu4,vuruldu5,vuruldu6,vuruldu7;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

public slots:
    void moveBalloon();
    void moveBalloon2();
    void moveBalloon3();
    void moveBalloon4();
    void moveBalloon5();
    void moveBalloon6();
    void moveBalloon7();

    void createBalloon();
    void createBalloon2();
    void createBalloon3();
    void createBalloon4();
    void createBalloon5();
    void createBalloon6();
    void createBalloon7();

    void count_time();


    int random_location();

};
#endif // MAINWINDOW_H
