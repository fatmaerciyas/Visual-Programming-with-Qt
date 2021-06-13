#ifndef NOT_H
#define NOT_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class not;
}

class not : public QDialog
{
    Q_OBJECT

public:
    explicit not(QWidget *parent = nullptr);
    ~not();

private:
    Ui::not *ui;
};

#endif // NOT_H
