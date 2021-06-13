#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "ogrenci.h"
#include "ders.h"
#include "notlar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/images/ogr.jpg");
    int w = ui->label_ogr->width();
    int h = ui->label_ogr->height();
    ui->label_ogr->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/img/images/ders.jpg");
    int w2 = ui->label_ders->width();
    int h2 = ui->label_ders->height();
    ui->label_ders->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    QPixmap pix3(":/img/images/notlar.jpg");
    int w3 = ui->label_not->width();
    int h3 = ui->label_not->height();
    ui->label_not->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));


    db.setDatabaseName("C:/Users/Lenovo/Desktop/19010011002/database.db");

    if(!db.open())
    {
        ui->statusbar->showMessage("Veri tabanına BAĞLANILAMADI");
    }
    else
    {
         ui->statusbar->showMessage("Veri tabanına Bağlandı");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ogr_clicked()
{
    ogrenci *ogr = new ogrenci(db);
    ogr->show();
}

void MainWindow::on_pushButton_ders_clicked()
{
    ders *des = new ders(db);
    des->show();
}

void MainWindow::on_pushButton_not_clicked()
{
    notlar *notl = new notlar(db);
    notl->show();
}
