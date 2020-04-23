#include "editequitment.h"
#include "ui_editequitment.h"
#include <QFile>
#include <QTextStream>
#include <QDataStream>

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <QMessageBox>
EditEquitment::EditEquitment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditEquitment)
{
    ui->setupUi(this);
}

EditEquitment::~EditEquitment()
{
    delete ui;
}

struct codeAndInfo{
    QString code;
    QString info;
};
void EditEquitment::on_pushButton_clicked()
{

    QString code=ui->lineEditcode->text();
    QString infos=ui->lineEditinfo->text();
    QVector <codeAndInfo> a;
    int i=0;
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream input(&f);
    codeAndInfo addToVec;
    input>>addToVec.code;
    addToVec.info=input.readLine();
    bool flag=false;
    while (!addToVec.info.isNull()) {

        if(addToVec.code==code){
            addToVec.info=infos;
            flag=true;
        }
        a<<addToVec;
       input>> addToVec.code;
       addToVec.info=input.readLine();
       i++;
    }
    int t=0;
    QString lineForAddToFile;
    std::fstream out;
    out.open("e:/AbolLife/git/DigitalMarketManager/items.txt",std::ios::out);


    QString allThing;
    while (t<a.size()) {
        lineForAddToFile=a[t].code+" "+a[t].info+"\n";
        allThing+=lineForAddToFile;
        t++;
    }
    std::string all=allThing.toStdString();

    out<<all;

    QMessageBox *myBox=new QMessageBox();
    if(flag==true){
        myBox->setText("equitment edited");
        myBox->setDefaultButton(QMessageBox::Ok);
        myBox->setIcon(QMessageBox::Information);
        myBox->setWindowTitle(" ");
    }
    if(flag==false){
        myBox->setText("equitment not found");
        myBox->setIcon(QMessageBox::Warning);
        myBox->setDefaultButton(QMessageBox::Ok);
        myBox->setWindowTitle(" ");

    }
    myBox->exec();

}



