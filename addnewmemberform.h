#ifndef ADDNEWMEMBERFORM_H
#define ADDNEWMEMBERFORM_H

#include <QWidget>

namespace Ui {
class addNewMemberForm;
}

class addNewMemberForm : public QWidget
{
    Q_OBJECT

public:
    explicit addNewMemberForm(QWidget *parent = nullptr);
    ~addNewMemberForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addNewMemberForm *ui;
};

#endif // ADDNEWMEMBERFORM_H
