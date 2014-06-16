#include "addcard.h"
#include "ui_addcard.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
addCard::addCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCard)
{
    ui->setupUi(this);
}

addCard::~addCard()
{
    delete ui;
}

void addCard::on_pushButton_clicked()
{
    QString id,de,name,gr;
    id=ui->c->text();
    de=ui->de->text();
    name=ui->name_2->text();
    gr=ui->gr->currentText();
    if(id==""||de==""||name==""||gr=="")
        QMessageBox::warning(NULL, tr("警告"), QString("输入不能为空！"));
    else
    {

    QSqlQuery q;
    q.prepare("select * from card where id = :id");
    q.bindValue(":id",id);
    if(!q.exec())
        qDebug()<<q.lastError();
    if(q.first()){
        QMessageBox::warning(NULL, tr("警告"), QString("该借书证ID已存在！"));
    }
    else{
    q.prepare("insert into card values(?,?,?,?)");
    q.addBindValue(id);
    q.addBindValue(name);
    q.addBindValue(de);
    q.addBindValue(gr);
    if(q.exec())
        QMessageBox::information(NULL, tr("提示"), tr("新增借书证成功！"));
    else
        qDebug()<<q.lastError();
    showAll();
        }
        }
}
void addCard::deleteRow()
{

        QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
        if (!model)
            return;

        QModelIndexList currentSelection = ui->tableView->selectionModel()->selectedIndexes();
        for (int i = 0; i < currentSelection.count(); ++i) {
            if (currentSelection.at(i).column() != 0)
                continue;
            model->removeRow(currentSelection.at(i).row());
        }

        showAll();

}
void addCard::showAll()
{
    model = new QSqlTableModel(ui->tableView);
    model->setTable("card");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "借书证ID");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "单位");
    model->setHeaderData(3, Qt::Horizontal, "类型");
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

}
void addCard::on_pushButton_5_clicked()
{
       model->database().transaction(); //开始事务操作
       qDebug()<<"1";
       if (model->submitAll()) // 提交所有被修改的数据到数据库中
       { qDebug()<<"2";
           model->database().commit(); //提交成功，事务将真正修改数据库数据
       } else { qDebug()<<"3";
           model->database().rollback(); //提交失败，事务回滚
           QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
       }
}

void addCard::on_pushButton_4_clicked()
{
    showAll();
}

void addCard::on_pushButton_3_clicked()
{
    deleteRow();
}
