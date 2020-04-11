#include "digitalmarketmanager.h"
#include "ui_digitalmarketmanager.h"

DigitalMarketManager::DigitalMarketManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitalMarketManager)
{
    ui->setupUi(this);
}

DigitalMarketManager::~DigitalMarketManager()
{
    delete ui;
}
