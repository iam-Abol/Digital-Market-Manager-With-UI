#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void updateClock();
    void on_actionexit_triggered();



    void on_ShowAllBTN_clicked();

    void on_AddNewEquitmentBTN_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
