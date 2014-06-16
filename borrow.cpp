#include "borrow.h"
#include "ui_borrow.h"
#include "globalvariables.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>
Borrow::Borrow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Borrow)
{
    ui->setupUi(this);
}

Borrow::~Borrow()
{
    delete ui;
}

void Borrow::on_query_clicked()
{
    if(ui->cid->text()=="")
        QMessageBox::warning(NULL, tr("警告"), tr("请输入借书证号！"));
    else {
        QSqlQueryModel *model = new QSqlQueryModel(ui->table);
        QSqlQuery q;
        q.prepare("select * from card where id = :cid");
        q.bindValue(":cid",ui->cid->text());
        if(!q.exec())
            qDebug()<<q.lastError();
        //qDebug()<<q.first();
        if(!q.next())
            QMessageBox::warning(NULL, tr("警告"), tr("不存在该借书证！"));
        else{
            q.prepare("select * from record where cid = :cid");
            q.bindValue(":cid",ui->cid->text());
            q.exec();
            model->setQuery(q);
            model->setHeaderData(0, Qt::Horizontal, "借书证号");
            model->setHeaderData(1, Qt::Horizontal, "书号");
            model->setHeaderData(2, Qt::Horizontal, "借书时间");
            model->setHeaderData(3, Qt::Horizontal, "还书时间");
            model->setHeaderData(4, Qt::Horizontal, "管理员ID");
            ui->table->setModel(model);
            ui->table->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
           // ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
            ui->table->setSelectionMode(QAbstractItemView::SingleSelection);
        }
    }
}

void Borrow::on_borrow_clicked()
{
    QString rtime,btime;
    rtime=ui->dateEdit->date().toString("yyyy-MM-dd");
    btime=QDateTime::currentDateTime().toString("yyyy-MM-dd");
    if(rtime<btime)
        QMessageBox::warning(NULL, tr("警告"), tr("还书时间应在借书时间之后！"));
    else{
        if(ui->bid->text()==""||ui->cid->text()=="")
            QMessageBox::warning(NULL, tr("警告"), tr("请输入借书证号或书号！"));
        else{
            QSqlQuery q;
            q.prepare("select * from card where id = :cid");
            q.bindValue(":cid",ui->cid->text());
            if(!q.exec())
                qDebug()<<q.lastError();
            if(!q.next())
                QMessageBox::warning(NULL, tr("警告"), tr("不存在该借书证！"));
            else{
                QSqlQuery q;
                q.prepare("select * from book where id = :bid");
                q.bindValue(":bid",ui->bid->text());
                if(!q.exec())
                    qDebug()<<q.lastError();
                //qDebug()<<q.first();
                if(!q.first()){
                    switch(QMessageBox::warning(this, tr("警告"),
                                          tr("不存在该书！您需要查询书籍吗？!"),
                                          QMessageBox::Yes|QMessageBox::No)){
                    case QMessageBox::Yes:
                       query.show();
                        break;
                    case QMessageBox::No:
                        break;
                    }}
                else{
                    if(q.value(8)==0){
                        QString ltime;
                        QSqlQuery query;
                        query.prepare("select * from record where bid = :bid and rtime > :btime order by rtime");
                        query.bindValue(":bid",ui->bid->text());
                        query.bindValue(":btime",btime);
                        query.exec();
                        query.first();

                        ltime=query.value(3).toString();
                        qDebug()<<"??";
                        QMessageBox::warning(NULL, tr("警告"), QString("该书已无库存！最近归还时间："+ltime));

                    }
                    else{
                        qDebug()<<rtime;
                        q.prepare("insert into record values(:cid,:bid,:btime,:rtime,:mid)");
                        //卡号, 书号,借期, 还期， 经手人（管理员ID）
                        q.bindValue(":cid",ui->cid->text());
                        q.bindValue(":bid",ui->bid->text());
                        q.bindValue(":btime",btime);
                        q.bindValue(":rtime",rtime);
                        q.bindValue(":mid",globalVariables::currentManager);
                        if(!q.exec())
                            qDebug()<<q.lastError();
                        else
                            QMessageBox::information(NULL, tr("提示"), tr("借出成功！"));
                        QSqlQuery q;
                        q.prepare("update book set remain = remain - 1 where id = :bid");
                        q.bindValue(":bid",ui->bid->text());
                        q.exec();
                    //qDebug()<<q.first();
                    }
                }
        }
    }
}
}

void Borrow::on_return_2_clicked()
{
    QString ctime;
    ctime=QDateTime::currentDateTime().toString("yyyy-MM-dd");

        if(ui->bid->text()==""||ui->cid->text()=="")
            QMessageBox::warning(NULL, tr("警告"), tr("请输入借书证号或书号！"));
        else{
            QSqlQuery q;
            q.prepare("select * from card where id = :cid");
            q.bindValue(":cid",ui->cid->text());
            if(!q.exec())
                qDebug()<<q.lastError();
            if(!q.next())
                QMessageBox::warning(NULL, tr("警告"), tr("不存在该借书证！"));
            else{
                QSqlQuery q;
                q.prepare("select * from book where id = :bid");
                q.bindValue(":bid",ui->bid->text());
                if(!q.exec())
                    qDebug()<<q.lastError();
                if(!q.first()){
                    switch(QMessageBox::warning(this, tr("警告"),
                                          tr("不存在该书！您需要查询书籍吗？!"),
                                          QMessageBox::Yes|QMessageBox::No)){
                    case QMessageBox::Yes:
                       query.show();
                        break;
                    case QMessageBox::No:
                        break;
                    }}
                else{


                        QSqlQuery q;
                        q.prepare("update book set remain = remain + 1 where id = :bid");
                        q.bindValue(":bid",ui->bid->text());
                        q.exec();
                        q.prepare("update record set rtime = :ctime where bid = :bid and cid = :cid ");
                        q.bindValue(":ctime",ctime);
                        q.bindValue(":bid",ui->bid->text());
                        q.bindValue(":cid",ui->cid->text());
                        q.exec();
                        QMessageBox::information(NULL, tr("提示"), tr("还书成功！"));

                }
        }

}
}
