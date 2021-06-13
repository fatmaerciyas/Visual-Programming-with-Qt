#ifndef DERS_H
#define DERS_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class ders;
}

class ders : public QDialog
{
    Q_OBJECT

public:
    explicit ders(QSqlDatabase,QWidget *parent = nullptr);
    ~ders();
    void listele();
    int sayac;

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_kaydet_clicked();

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

private:
    Ui::ders *ui;

    QSqlQuery *sorgu;
    QSqlTableModel *model;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;

};

#endif // DERS_H
