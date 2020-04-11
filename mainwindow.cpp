#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qapplication.h>
#include <qtimer.h>
#include <QTime>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect (timer,SIGNAL(timeout()),SLOT(updateClock()));
}
void MainWindow::updateClock(){
    QString time=QTime().currentTime().toString("->hh:mm:ss<-");
    ui->label->setText(time);
}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionexit_triggered()
{
    QMessageBox *myBox=new QMessageBox();
    myBox->setText("are you leave ?");
    myBox->setIcon(QMessageBox::Question);
    myBox->setStandardButtons(QMessageBox::Yes |QMessageBox::No);
    myBox->setDefaultButton(QMessageBox::Yes);
    myBox->setWindowTitle(" ");
    int r=myBox->exec();
    switch (r) {
    case QMessageBox::Yes :
        QApplication::exit();
        break;
    }
}