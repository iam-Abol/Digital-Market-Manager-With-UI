#include "addnewequitment.h"
#include "ui_addnewequitment.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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

void addNewEquitment::on_pushButton_clicked()
{
    QString allInfo=ui->lineEditCode->text()+" ";
    allInfo+=ui->lineEditName->text()+" ";
    allInfo+=ui->lineEditBrand->text()+" ";

    allInfo+=ui->lineEditNumber->text()+" ";
    allInfo+=ui->lineEditDetails->text()+" ";
    allInfo+=ui->lineEditPrice->text()+" ";

    allInfo+=ui->lineEditotherInformation->text();
    ////////////////////
    QMessageBox *myBox = new QMessageBox();
    myBox->setWindowTitle(" ");
    myBox->setStandardButtons(QMessageBox::Ok);
    myBox->setDefaultButton(QMessageBox::Ok);

    ///////////////////
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream inputOut(&f);
    bool flag = true;
    QString info=inputOut.readLine();
    while (!info.isNull()) {
        if(info==allInfo){
            flag = false;
            myBox->setText("New equitment not added because A similar device is available from the imported device");
            myBox->setIcon(QMessageBox::Warning);
            break;
        }
        info=inputOut.readLine();
    }
    if(flag==true){

        myBox->setText("New equitment added");
        myBox->setIcon(QMessageBox::Information);
        inputOut<<"\n"<<allInfo;
    }



    myBox->exec();
}
