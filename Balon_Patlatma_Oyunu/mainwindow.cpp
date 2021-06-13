#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QPixmap>
#include <QRandomGenerator>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    vurulan_balon_sayisi = kacan_balon_sayisi = 0;
    vuruldu1 = vuruldu2 = vuruldu3 = vuruldu4 = vuruldu5 = vuruldu6 = vuruldu7 = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(createBalloon())); // her 2 saniyed createBallon fonkunu çağır
    timer->start(5000);

    time = 0;
    count = 0;
    QTimer *tut = new QTimer(this);
    connect(tut, SIGNAL(timeout()),this, SLOT(count_time()));
    tut->start(1000);

    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this, SLOT(createBalloon2())); // her 2 saniyed createBallon fonkunu çağır
    timer2->start(7000);

    QTimer *timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()),this, SLOT(createBalloon3())); // her 2 saniyed createBallon fonkunu çağır
    timer3->start(8000);

    QTimer *timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()),this, SLOT(createBalloon4())); // her 2 saniyed createBallon fonkunu çağır
    timer4->start(10000);

    QTimer *timer5 = new QTimer(this);
    connect(timer5, SIGNAL(timeout()),this, SLOT(createBalloon5())); // her 2 saniyed createBallon fonkunu çağır
    timer5->start(11000);

    QTimer *timer6 = new QTimer(this);
    connect(timer6, SIGNAL(timeout()),this, SLOT(createBalloon6())); // her 2 saniyed createBallon fonkunu çağır
    timer6->start(12000);

    QTimer *timer7 = new QTimer(this);
    connect(timer7, SIGNAL(timeout()),this, SLOT(createBalloon7())); // her 2 saniyed createBallon fonkunu çağır
    timer7->start(13000);

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::moveBalloon()
{
    y1 += 5;
    ui->pushButton->move(QPoint(x,y1));

}

void MainWindow::moveBalloon2()
{
    y2 += 5;
    ui->pushButton_2->move(QPoint(a,y2));
}


void MainWindow::moveBalloon3()
{
    y3 += 5;
    ui->pushButton_3->move(QPoint(b,y3));
}

void MainWindow::moveBalloon4()
{
    y4 += 5;
    ui->pushButton_4->move(QPoint(c,y4));
}

void MainWindow::moveBalloon5()
{
    y5 += 5;
    ui->pushButton_5->move(QPoint(d,y5));
}

void MainWindow::moveBalloon6()
{
    y6 += 5;
    ui->pushButton_6->move(QPoint(e,y6));
}


void MainWindow::moveBalloon7()
{
    y7 += 5;
    ui->pushButton_7->move(QPoint(f,y7));
}




int MainWindow::random_location()
{
    quint32 v = QRandomGenerator::global()->bounded(20,1300);
    return v;
}



void MainWindow::createBalloon()
{
    if(sayac1 == 0)
    {
        y1 = 30;
    }
    else if(sayac1 % 2 == 1)
    {
       y1 = 30;
       sayac1 = 0;
       x = random_location();
       ui->pushButton->setStyleSheet("image :  url(:/img/images/0.jpg)");
       if(vuruldu1 == true)
       {
           vuruldu1 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }
    }
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon()));
    timer->start(100);
    sayac1++;

}

void MainWindow::createBalloon2()
{
    if(sayac2 == 0)
    {
        y2 = 30;
    }
    else if(sayac2 % 2 == 1)
    {
       y2 = 30;
       sayac2 = 0;
       a = random_location();
       ui->pushButton_2->setStyleSheet("image :  url(:/img/images/1.jpg)");
       if(vuruldu2 == true)
       {
           vuruldu2 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }

    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon2()));
     timer->start(100);
     sayac2++;
}

void MainWindow::createBalloon3()
{
    if(sayac3 == 0)
    {
        y3 = 30;
    }
    else if(sayac3 % 2 == 1)
    {
       y3 = 30;
       sayac3 = 0;
       b = random_location();
       ui->pushButton_3->setStyleSheet("image :  url(:/img/images/3.jpg)");
       if(vuruldu3 == true)
       {
           vuruldu3 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }
    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon3()));
     timer->start(100);
     sayac3++;
}

void MainWindow::createBalloon4()
{
    if(sayac4 == 0)
    {
        y4 = 30;
    }
    else if(sayac4 % 2 == 1)
    {
       y4 = 30;
       sayac4 = 0;
       c = random_location();
        ui->pushButton_4->setStyleSheet("image :  url(:/img/images/2.jpg)");
        if(vuruldu4 == true)
        {
            vuruldu4 = false;
        }
        else
        {
            kacan_balon_sayisi++;
            ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
        }
    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon4()));
     timer->start(100);
     sayac4++;
}

void MainWindow::createBalloon5()
{
    if(sayac5 == 0)
    {
        y5 = 30;
    }
    else if(sayac5 % 2 == 1)
    {
       y5 = 30;
       sayac5 = 0;
       d = random_location();
       ui->pushButton_5->setStyleSheet("image :  url(:/img/images/4.jpg)");
       if(vuruldu5 == true)
       {
           vuruldu5 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }
    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon5()));
     timer->start(100);
     sayac5++;
}

void MainWindow::createBalloon6()
{
    if(sayac6 == 0)
    {
        y6 = 30;
    }
    else if(sayac6 % 2 == 1)
    {
       y6 = 30;
       sayac6 = 0;
       e = random_location();
       ui->pushButton_6->setStyleSheet("image :  url(:/img/images/5.jpg)");
       if(vuruldu6 == true)
       {
           vuruldu6 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }
    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon6()));
     timer->start(100);
     sayac6++;
}

void MainWindow::createBalloon7()
{
    if(sayac7 == 0)
    {
        y7 = 30;
    }
    else if(sayac7 % 2 == 1)
    {
       y7 = 30;
       sayac7 = 0;
       f = random_location();
       ui->pushButton_7->setStyleSheet("image :  url(:/img/images/6.jpg)");
       if(vuruldu7 == true)
       {
           vuruldu7 = false;
       }
       else
       {
           kacan_balon_sayisi++;
           ui->lineEdit_kacan->setText(QString::number(kacan_balon_sayisi));
       }
    }
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(moveBalloon7()));
     timer->start(100);
     sayac7++;
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu1 = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu2 = true;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu3 = true;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu4 = true;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu5 = true;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu6 = true;
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setStyleSheet("image :  url(:/img/images/patlama.jpg)");
    vurulan_balon_sayisi++;
    ui->lineEdit_vurulan->setText(QString::number(vurulan_balon_sayisi));
    vuruldu7 = true;
}

void MainWindow::count_time()
{
    count++;
    if(count < 7)
    {

    }
    else
    {
        time++;
    }
    ui->lineEdit_sure->setText(QString::number(time));
}
