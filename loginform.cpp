#include "loginform.h"
#include "ui_loginform.h"

loginForm::loginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
}

loginForm::~loginForm()
{
    delete ui;
}
