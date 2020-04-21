#ifndef SEARCHEQUITMENTFORM_H
#define SEARCHEQUITMENTFORM_H

#include <QWidget>

namespace Ui {
class SearchEquitmentForm;
}

class SearchEquitmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchEquitmentForm(QWidget *parent = nullptr);
    ~SearchEquitmentForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchEquitmentForm *ui;
};

#endif // SEARCHEQUITMENTFORM_H
