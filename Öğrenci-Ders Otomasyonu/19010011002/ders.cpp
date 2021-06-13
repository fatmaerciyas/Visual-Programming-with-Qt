#include "ders.h"
#include "ui_ders.h"
# include <QString>
#include <QSqlRecord>

ders::ders(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ders)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();

    model = new QSqlTableModel();
    model->setTable("dersler");
    ui->tableView->setModel(model);
    model->select();

}

ders::~ders()
{
    delete ui;
}

void ders::listele()
{
    model3 = new QSqlQueryModel();
    if(sorgu->exec("Select * from dersler"))
    {
        model3->setQuery(*sorgu);
        ui->tableView->setModel(model3);
    }
    else
    {
        qDebug() << sorgu->lastError();
    }
}



void ders::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_dersKodu->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_dersAdi->setText(model->index(index.row(),1).data().toString());


    QString indis = model->index(index.row(),0).data().toString();
    int ders_kodu = indis.toInt();
    QSqlQuery sorgu;
    sorgu.prepare("select * from notlar WHERE ders_kodu= ?");
    sorgu.addBindValue(ders_kodu);
    sorgu.exec();

    model2 = new QSqlQueryModel();
    model2->setQuery(sorgu);
    ui->tableView_ogr->setModel(model2);
}


void ders::on_btn_kaydet_clicked()
{
    sorgu->prepare("insert into dersler(ders_adi) values(?)");
    if(ui->lineEdit_dersAdi->text() == "")
    {
        QMessageBox::critical(this,"HATA","Gerekli alanları doldurunuz!",sorgu->lastError().text());
    }
    else
    {
        sorgu->addBindValue(ui->lineEdit_dersAdi->text());

        if(!sorgu->exec())
        {
            QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
        }
        listele();
    }
}

void ders::on_btn_guncelle_clicked()
{
    sorgu->prepare("update dersler set ders_adi =? where ders_kodu=?");
    sorgu->addBindValue(ui->lineEdit_dersAdi->text());
    sorgu->addBindValue(ui->lineEdit_dersKodu->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
    }
    listele();
}

void ders::on_btn_sil_clicked()
{
    sorgu->prepare("select ogr_no from notlar where ders_kodu =?");
    sorgu->addBindValue(ui->lineEdit_dersKodu->text().toInt());
    sorgu->exec();

    if(sorgu->next())
    {
        QMessageBox::critical(this,"HATA!","Bu derse ait öğrenciler vardır silinemez!",sorgu->lastError().text());

    }
    else
    {
        sorgu->prepare("delete from dersler where ders_kodu =?");
        sorgu->addBindValue(ui->lineEdit_dersKodu->text().toInt());
        if(!sorgu->exec())
        {
            QMessageBox::critical(this,"HATA!",sorgu->lastError().text());
        }
        listele();
    }

}
