#ifndef ADDMANAGER_H
#define ADDMANAGER_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class addManager;
}

class addManager : public QDialog
{
    Q_OBJECT

public:
    explicit addManager(QWidget *parent = 0);
    void showAll();
    void deleteRow();

    ~addManager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


     void on_pushButton_5_clicked();

private:
    Ui::addManager *ui;
    QSqlTableModel *model;

};

#endif // ADDMANAGER_H
