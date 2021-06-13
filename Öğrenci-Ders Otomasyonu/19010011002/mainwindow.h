#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ogr_clicked();

    void on_pushButton_ders_clicked();

    void on_pushButton_not_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");

    QSqlTableModel *model;
    QSqlQueryModel *model2;
};
#endif // MAINWINDOW_H
