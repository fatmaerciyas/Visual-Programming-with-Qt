#include "ogrenci.h"
#include "ui_ogrenci.h"

ogrenci::ogrenci(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogrenci)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();

    model2 = new QSqlTableModel();
    model2->setTable("ogrenci");
    ui->tableView->setModel(model2);
    model2->select();
}

ogrenci::~ogrenci()
{
    delete ui;
}

void ogrenci::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from ogrenci"))
    {
        model->setQuery(*sorgu);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << sorgu->lastError();
    }
}



void ogrenci::on_btn_kaydet_clicked()
{
    sorgu->prepare("insert into ogrenci(ogr_ad,ogr_soyad) values(?,?)");
    if(ui->lineEdit_ad->text() == "" || ui->lineEdit_soyad->text() == "")
    {
        QMessageBox::critical(this,"HATA","Gerekli alanları doldurunuz!",sorgu->lastError().text());
    }
    else
    {
        sorgu->addBindValue(ui->lineEdit_ad->text());
        sorgu->addBindValue(ui->lineEdit_soyad->text());

        if(!sorgu->exec())
        {
            QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
        }
        listele();
    }
}

void ogrenci::on_btn_sil_clicked()
{
    sorgu->prepare("select ders_kodu from notlar where ogr_no =?");
    sorgu->addBindValue(ui->lineEdit_no->text().toInt());
    sorgu->exec();

    if(sorgu->next())
    {
        QMessageBox::information(this,"HATA!","Bu öğrenci silinemez, Öğrenci üzerine kayıtlı dersler vardır!",sorgu->lastError().text());
    }

    else
    {
        sorgu->prepare("delete from ogrenci where ogr_no =?");
        sorgu->addBindValue(ui->lineEdit_no->text().toInt());
        if(!sorgu->exec())
        {
            QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
        }
        listele();
    }

}


void ogrenci::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_no->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_ad->setText(model->index(index.row(),1).data().toString());
    ui->lineEdit_soyad->setText(model->index(index.row(),2).data().toString());

}

void ogrenci::on_btn_guncelle_clicked()
{
    sorgu->prepare("update ogrenci set ogr_ad=? , ogr_soyad=? where ogr_no  =?");
    sorgu->addBindValue(ui->lineEdit_ad->text());
    sorgu->addBindValue(ui->lineEdit_soyad->text());
    sorgu->addBindValue(ui->lineEdit_no->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
    }
    listele();
}
