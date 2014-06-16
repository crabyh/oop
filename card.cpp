#include "card.h"
#include "ui_card.h"

card::card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::card)
{
    ui->setupUi(this);
}

card::~card()
{
    delete ui;
}
