#include "notlar.h"
#include "ui_notlar.h"

notlar::notlar(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notlar)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    //listele();

    model2 = new QSqlTableModel();
    model2->setTable("ogrenci");
    ui->tableView_ogr->setModel(model2);
    model2->select();

    model3 = new QSqlTableModel();
    model3->setTable("dersler");
    ui->tableView_ders->setModel(model3);
    model3->select();

    model4 = new QSqlTableModel();
    model4->setTable("notlar");
    ui->tableView_notlar->setModel(model4);
    model4->select();


}

notlar::~notlar()
{
    delete ui;
}

void notlar::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("Select * from notlar"))
    {
        model->setQuery(*sorgu);
        ui->tableView_notlar->setModel(model);
    }
    else
    {
        qDebug() << sorgu->lastError();
    }
}


void notlar::on_tableView_ogr_clicked(const QModelIndex &index)
{
    ui->lineEdit_ogrNo->setText(model2->index(index.row(),0).data().toString());
}

void notlar::on_tableView_ders_clicked(const QModelIndex &index)
{
    ui->lineEdit_dersKodu->setText(model3->index(index.row(),0).data().toString());
}

void notlar::on_btn_kaydet_clicked()
{
    sorgu->prepare("select ders_kodu from notlar where ogr_no=?");
    sorgu->addBindValue(ui->lineEdit_ogrNo->text().toInt());
    sorgu->exec();
    int bulundu = 0;

    while(sorgu->next())
    {
        int dersKodu = sorgu->value(0).toInt();
        if(dersKodu == ui->lineEdit_dersKodu->text().toInt())
        {

            bulundu =1;
            break;
        }
    }

    if(bulundu == 0)
    {

        sorgu->prepare("insert into notlar(ogr_no , ders_kodu , vize_not , final_not , gecme_notu) values(?,?,?,?,?)");

        if(ui->lineEdit_vizeNot->text() == "" || ui->lineEdit_finalNot->text() == "")
        {
            QMessageBox::critical(this,"HATA","Gerekli alanları doldurunuz!",sorgu->lastError().text());
        }

        else
        {
            double a = (ui->lineEdit_vizeNot->text().toDouble()) * 0.4;
            double b = (ui->lineEdit_finalNot->text().toDouble()) * 0.6;
            double gecme_n = a+b;

            sorgu->addBindValue(ui->lineEdit_ogrNo->text().toInt());
            sorgu->addBindValue(ui->lineEdit_dersKodu->text().toInt());
            sorgu->addBindValue(ui->lineEdit_vizeNot->text().toInt());
            sorgu->addBindValue(ui->lineEdit_finalNot->text().toInt());
            sorgu->addBindValue(gecme_n);


            if(!sorgu->exec())
            {
                QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
            }
            listele();
        }
    }

    else
    {
        QMessageBox::information(this,"HATA","Bu öğrenci üzerinde bu ders zaten tanımlı!",sorgu->lastError().text());
    }


}
