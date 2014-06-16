#ifndef INSERT_H
#define INSERT_H

#include <QDialog>

namespace Ui {
class insert;
}

class insert : public QDialog
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = 0);
    ~insert();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::insert *ui;
    void showUpdate();
};

#endif // INSERT_H
