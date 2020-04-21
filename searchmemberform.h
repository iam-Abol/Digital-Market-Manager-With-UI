#ifndef SEARCHMEMBERFORM_H
#define SEARCHMEMBERFORM_H

#include <QWidget>

namespace Ui {
class SearchMemberForm;
}

class SearchMemberForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchMemberForm(QWidget *parent = nullptr);
    ~SearchMemberForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchMemberForm *ui;
};

#endif // SEARCHMEMBERFORM_H
