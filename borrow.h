#ifndef BORROW_H
#define BORROW_H
#include "querywindow.h"
#include <QDialog>

namespace Ui {
class Borrow;
}

class Borrow : public QDialog
{
    Q_OBJECT

public:
    explicit Borrow(QWidget *parent = 0);
    ~Borrow();

private slots:
    void on_query_clicked();

    void on_borrow_clicked();

    void on_return_2_clicked();

private:
    Ui::Borrow *ui;
    QueryWindow query;
};

#endif // BORROW_H
