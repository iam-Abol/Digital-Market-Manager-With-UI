#include "editequitment.h"
#include "ui_editequitment.h"
#include <QFile>
#include <QTextStream>
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
QString EditEquitment::search(QString code)
{


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
    if(flag==true){
        return Allinfos;
    }



}
void EditEquitment::on_pushButton_clicked()
{
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream input(&f);
   QString codeFromfile;
    input>>codeFromfile;


    QString infosFromFile=input.readLine();
    QString allThing="";
    QString code=ui->lineEditinfo->text();
    QString info=search(code);

    while (!infosFromFile.isNull()) {
        if(info==""){
            ui->label->setText("equitment not found");
        }
        else {
            ui->label->setText(info);

            QString newInfo=ui->lineEditnew->text();
            if(codeFromfile==code){
                allThing+=code+newInfo+"\n";
            }
            else {
                allThing+=codeFromfile+infosFromFile+"\n";
            }

        }
        code=ui->lineEditinfo->text();
        infosFromFile=input.readLine();

    }
    ui->label->setText(allThing);
}

void EditEquitment::on_pushButton_2_clicked()
{

}
