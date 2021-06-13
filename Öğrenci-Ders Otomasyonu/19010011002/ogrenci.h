#ifndef OGRENCI_H
#define OGRENCI_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class ogrenci;
}

class ogrenci : public QDialog
{
    Q_OBJECT

public:
    explicit ogrenci(QSqlDatabase,QWidget *parent = nullptr);
    ~ogrenci();
    void listele();

private slots:
    void on_btn_kaydet_clicked();

    void on_btn_sil_clicked();

    void on_btn_guncelle_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ogrenci *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlTableModel *model2;
};

#endif // OGRENCI_H
