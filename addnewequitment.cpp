#include "addnewequitment.h"
#include "ui_addnewequitment.h"

addNewEquitment::addNewEquitment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addNewEquitment)
{
    ui->setupUi(this);
}

addNewEquitment::~addNewEquitment()
{
    delete ui;
}
