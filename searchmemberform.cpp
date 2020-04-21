#include "searchmemberform.h"
#include "ui_searchmemberform.h"

SearchMemberForm::SearchMemberForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchMemberForm)
{
    ui->setupUi(this);
}

SearchMemberForm::~SearchMemberForm()
{
    delete ui;
}
