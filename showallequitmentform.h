#ifndef SHOWALLEQUITMENTFORM_H
#define SHOWALLEQUITMENTFORM_H

#include <QWidget>

namespace Ui {
class ShowAllEquitmentForm;
}

class ShowAllEquitmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShowAllEquitmentForm(QWidget *parent = nullptr);
    ~ShowAllEquitmentForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowAllEquitmentForm *ui;
};

#endif // SHOWALLEQUITMENTFORM_H
