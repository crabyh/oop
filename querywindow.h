#ifndef QUERYWINDOW_H
#define QUERYWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class QueryWindow;
}

class QueryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QueryWindow(QWidget *parent = 0);
    void showAll();
    void deleteRow();
    ~QueryWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::QueryWindow *ui;
    QSqlTableModel *model;
};

#endif // QUERYWINDOW_H
