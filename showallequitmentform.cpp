#include "showallequitmentform.h"
#include "ui_showallequitmentform.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;
ShowAllEquitmentForm::ShowAllEquitmentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowAllEquitmentForm)
{
    ui->setupUi(this);


}

ShowAllEquitmentForm::~ShowAllEquitmentForm()
{
    delete ui;
}
void ShowAllEquitmentForm::getAllInfo(QString path){
    QFile f(path);
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream readd(&f);
    QString info=readd.readLine();
    QString allInfo;
    while(!info.isNull()){
        allInfo+=info+"\n";
        info=readd.readLine();
    }
    ui->label->setText(allInfo);

}
void ShowAllEquitmentForm::on_pushButton_clicked()
{


    QString path="e:/AbolLife/git/DigitalMarketManager/items.txt";

    getAllInfo(path);
}
