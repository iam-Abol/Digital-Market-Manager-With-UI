#include "addnewmemberform.h"
#include "ui_addnewmemberform.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
addNewMemberForm::addNewMemberForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addNewMemberForm)
{
    ui->setupUi(this);
}

addNewMemberForm::~addNewMemberForm()
{
    delete ui;
}

void addNewMemberForm::on_pushButton_clicked()
{
    QString AllInfo;
    bool flag=true;
    AllInfo=ui->lineEditCode->text()+" ";
    AllInfo+=ui->lineEditName->text()+" ";
    AllInfo+=ui->lineEditLastName->text()+" ";
    AllInfo+=ui->lineEditPhoneNumber->text();
    //////////////////////////////////////////////////////////////////////////////
    QMessageBox *myBox=new QMessageBox();
    myBox->setStandardButtons(QMessageBox::Ok);
    myBox->setDefaultButton(QMessageBox::Ok);

    //////////////////////////////////////////////////////////////////////////////
    QFile f("e:/AbolLife/git/DigitalMarketManager/customer.txt");
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream inputout(&f);
    QString info=inputout.readLine();
    while(!info.isNull()){
        if(info==AllInfo){
            flag=false;
        }
        info=inputout.readLine();
    }
    //////////////////////////////////////////////////////////////////////////////
    if(flag==true){
        inputout<<"\n"<<AllInfo;
        myBox->setWindowTitle("member Adding was successful");
        myBox->setIcon(QMessageBox::Information);
        myBox->setInformativeText("\n! Member added !\n");
    }
    else {
        myBox->setWindowTitle("member Adding was not successful");
        myBox->setIcon(QMessageBox::Warning);
        myBox->setInformativeText("\n! Member is not added because member similar to existing member exists !\n");
    }
    myBox->exec();

    f.close();
}
