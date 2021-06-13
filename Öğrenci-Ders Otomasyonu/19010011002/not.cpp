#include "not.h"
#include "ui_not.h"

not::not(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::not)
{
    ui->setupUi(this);
}

not::~not()
{
delete ui;
}
