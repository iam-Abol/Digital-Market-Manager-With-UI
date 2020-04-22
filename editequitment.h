#ifndef EDITEQUITMENT_H
#define EDITEQUITMENT_H

#include <QWidget>

namespace Ui {
class EditEquitment;
}

class EditEquitment : public QWidget
{
    Q_OBJECT

public:
    explicit EditEquitment(QWidget *parent = nullptr);
    ~EditEquitment();

private slots:
    void on_pushButton_clicked();
    QString search(QString code);
    void on_pushButton_2_clicked();

private:
    Ui::EditEquitment *ui;
};

#endif // EDITEQUITMENT_H
