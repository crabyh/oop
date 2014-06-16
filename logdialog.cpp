#include "logdialog.h"
#include "ui_logdialog.h"
#include "Database.h"
#include "globalVariables.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

LogDialog::LogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogDialog)
{
    ui->setupUi(this);
    ui->pwdedit->setEchoMode(QLineEdit::Password);
}

LogDialog::~LogDialog()
{
    delete ui;
}

void LogDialog::on_pushButton_clicked()
{
    QSqlQuery q;
    q.exec("select * from manager");
    while(q.next()){
    if(ui->idedit->text() ==q.value(0).toString() &&
              ui->pwdedit->text() == q.value(1).toString())
       {
          globalVariables::currentManager=q.value(0).toString();
         // qDebug()<<globalVariables::currentManager;
          accept();
          return;
       }
    }
          QMessageBox::warning(this, tr("Waring"),
                                tr("用户名或密码错误!"),
                                QMessageBox::Yes);

    ui->idedit->clear();
    ui->pwdedit->clear();
    ui->idedit->setFocus();
}

void LogDialog::on_pushButton_2_clicked()
{
    exit(0);
}
