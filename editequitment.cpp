#include "editequitment.h"
#include "ui_editequitment.h"
#include <QFile>
#include <QTextStream>
#include <QDataStream>
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
int numberofLine(){
    int i=1;
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream input(&f);
    QString line=input.readLine();
    while(!line.isNull()){
        line=input.readLine();
        i++;
    }
    return i;
    f.close();
}
void EditEquitment::on_pushButton_clicked()
{
    struct codeAndInfo{
        QString code;
        QString info;
    };
    ui->label->setText("hahahhaah");
    int numberofLines=numberofLine();
    codeAndInfo codeandinfo[numberofLines];
    int i=0;
    int r=0;
    int t=0;
    ///////////////////////////////
    QFile f("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream input(&f);
    QString code=ui->lineEditcode->text();
    QString info=ui->lineEditinfo->text();
    ////////////////////////////////
    QString infoFile;
    QString codefile;
    QFile f1("e:/AbolLife/git/DigitalMarketManager/items.txt");
    f.open(QFile::ReadOnly | QFile::Text |QFile::Text);
    QTextStream in(&f);
    in>>code;
    infoFile=in.readLine();
    while (!info.isNull()) {
        codeandinfo[r].code=codefile;
        codeandinfo[r].info=infoFile;
        in>>code;
        infoFile=in.readLine();
        r++;
    }
    ////////////////////////////////
    bool flag=false;
    while (i<numberofLines) {
        if(codeandinfo[i].code==code){
            codeandinfo[i].info=info;
            flag=true;
        }

        i++;
    }
    ///////////////////////////

    f.close();
    f.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream out(&f);
    QString allthing="";
    while(t<numberofLines){
        allthing+=codeandinfo[t].code+codeandinfo->info+"\n";
    }
    out<<allthing;
    //////////////////////////////
    if(flag==true){
        ui->label->setText("equitment edited");
    }
    else {
        ui->label->setText("equitment not found");

    }

}



