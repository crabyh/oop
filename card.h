#ifndef CARD_H
#define CARD_H

#include <QDialog>

namespace Ui {
class card;
}

class card : public QDialog
{
    Q_OBJECT

public:
    explicit card(QWidget *parent = 0);
    ~card();

private:
    Ui::card *ui;
};

#endif // CARD_H
