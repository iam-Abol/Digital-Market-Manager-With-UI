#ifndef ADDNEWEQUITMENT_H
#define ADDNEWEQUITMENT_H

#include <QWidget>

namespace Ui {
class addNewEquitment;
}

class addNewEquitment : public QWidget
{
    Q_OBJECT

public:
    explicit addNewEquitment(QWidget *parent = nullptr);
    ~addNewEquitment();

private:
    Ui::addNewEquitment *ui;
};

#endif // ADDNEWEQUITMENT_H
