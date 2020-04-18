#include "showallequitmentform.h"
#include "ui_showallequitmentform.h"
#include <fstream>
#include <string>
#include <iostream>
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

void ShowAllEquitmentForm::on_pushButton_clicked()
{
    ifstream input("items.txt");


    string allInfo="";
    while(input){
         string OneEquitmentInfo;
        getline(input,OneEquitmentInfo);
        allInfo += OneEquitmentInfo+"\n";
    }



    ui->label->setText("infos");
}
