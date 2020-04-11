#ifndef DIGITALMARKETMANAGER_H
#define DIGITALMARKETMANAGER_H

#include <QWidget>

namespace Ui {
class DigitalMarketManager;
}

class DigitalMarketManager : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalMarketManager(QWidget *parent = nullptr);
    ~DigitalMarketManager();
private slots:
    void on_actionexit_triggered();

    void updateClock();
private:
    Ui::DigitalMarketManager *ui;
};

#endif // DIGITALMARKETMANAGER_H
