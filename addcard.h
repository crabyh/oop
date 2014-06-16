#ifndef ADDCARD_H
#define ADDCARD_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class addCard;
}

class addCard : public QDialog
{
    Q_OBJECT

public:
    explicit addCard(QWidget *parent = 0);
    void showAll();
    void deleteRow();
    ~addCard();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addCard *ui;
    QSqlTableModel *model;
};

#endif // ADDCARD_H
