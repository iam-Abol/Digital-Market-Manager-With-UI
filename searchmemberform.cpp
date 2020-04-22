#include "searchmemberform.h"
#include "ui_searchmemberform.h"
#include <QFile>
#include <QTextStream>
#include <QString>
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

void SearchMemberForm::on_pushButton_clicked()
{
    QString code=ui->lineEdit->text();
    QString codeFromFile;
    QString info;
    bool flag=false;
    QFile f("e:/AbolLife/git/DigitalMarketManager/customer.txt");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream input(&f);

    input>>codeFromFile;
    info=input.readLine();

    QString allInfo="";
    while (!info.isNull()) {
        if(codeFromFile==code){
            allInfo+=code+info+"\n";
            flag=true;
        }
        input>>codeFromFile;
        info=input.readLine();
    }
    if(flag==false){

        ui->plainTextEdit->setPlainText("member not found");
    }
    else {

        ui->plainTextEdit->setPlainText("member information :\n"+allInfo);
    }
    ui->lineEdit->clear();
    f.close();
}
