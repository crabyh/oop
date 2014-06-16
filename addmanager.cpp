#include "addmanager.h"
#include "ui_addmanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
addManager::addManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addManager)
{
    ui->setupUi(this);
}


addManager::~addManager()
{
    delete ui;
}

void addManager::showAll()
{
    model = new QSqlTableModel(ui->tableView);
    model->setTable("manager");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "管理员ID");
    model->setHeaderData(1, Qt::Horizontal, "密码");
    model->setHeaderData(2, Qt::Horizontal, "姓名");
    model->setHeaderData(3, Qt::Horizontal, "联系方式");
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

}

void addManager::deleteRow()
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

void addManager::on_pushButton_clicked()
{
    QString id,pwd,name,phone;
    id=ui->m->text();
    pwd=ui->pwd->text();
    name=ui->name->text();
    phone=ui->phone->text();
    if(id==""||pwd==""||name==""||phone=="")
        QMessageBox::warning(NULL, tr("警告"), QString("输入不能为空！"));
    else
    {

    QSqlQuery q;
    q.prepare("select * from manager where id = :id");
    q.bindValue(":id",id);
    if(!q.exec())
        qDebug()<<q.lastError();
    if(q.first()){
        QMessageBox::warning(NULL, tr("警告"), QString("该管理员ID已存在！"));
    }
    else{
    q.prepare("insert into manager values(?,?,?,?)");
    q.addBindValue(id);
    q.addBindValue(pwd);
    q.addBindValue(name);
    q.addBindValue(phone);
    if(q.exec())
        QMessageBox::information(NULL, tr("提示"), tr("新增管理员成功！"));
    else
        qDebug()<<q.lastError();
    showAll();
        }
        }
}

void addManager::on_pushButton_3_clicked()
{
    deleteRow();
}

void addManager::on_pushButton_4_clicked()
{
    showAll();
}

void addManager::on_pushButton_5_clicked()
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
