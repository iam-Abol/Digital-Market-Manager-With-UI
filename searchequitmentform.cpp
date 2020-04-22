#include "searchequitmentform.h"
#include "ui_searchequitmentform.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
SearchEquitmentForm::SearchEquitmentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchEquitmentForm)
{
    ui->setupUi(this);
}

SearchEquitmentForm::~SearchEquitmentForm()
{
    delete ui;
}

void SearchEquitmentForm::on_pushButton_clicked()
{

    QString code=ui->lineEdit->text();
    QString codeFromFile;
    QString info;
    bool flag=false;
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream input(&f);
    input>>codeFromFile;
    info=input.readLine();
    QString Allinfos="";
    while(!info.isNull()){
        if(codeFromFile==code){
            Allinfos+=code+info+"\n";
            flag=true;

        }
        input>>codeFromFile;
        info=input.readLine();
    }
    if(flag==false){
        ui->plainTextEdit->setPlainText("equitment not found");
    }
    else {
        ui->plainTextEdit->setPlainText("equitment information : \n"+Allinfos);
    }
    ui->lineEdit->clear();
    f.close();

}
