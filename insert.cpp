#include "insert.h"
#include "ui_insert.h"
#include "Database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>



insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
}

insert::~insert()
{
    delete ui;
}

void insert::on_pushButton_clicked()
{   if(ui->title->text()==""||ui->author->text()==""||ui->publisher->text()==""||ui->year->text()==""||ui->price->text()==""||ui->total->text()=="")
        QMessageBox::warning(NULL, tr("警告"), tr("输入不能为空！"));
    else{
    QSqlQuery q;//书号, 类别, 书名, 出版社, 年份, 作者, 价格, 总藏书量, 库存

    q.prepare("select * from book where id = :id");
    q.bindValue(":id",ui->id_2->text());
    if(!q.exec())
        qDebug()<<q.lastError();
    if(q.first()){
        QMessageBox::warning(NULL, tr("警告"), QString("该书号已存在！"));
    }
    else{

    q.prepare("insert into book(id,genre,title,publisher,year,author,price,total,remain) values(?,?,?,?,?,?,?,?,?)");
    q.addBindValue(ui->id_2->text());
    q.addBindValue(ui->genre->currentText());
    q.addBindValue(ui->title->text());
    q.addBindValue(ui->publisher->text());
    q.addBindValue(ui->year->text());
    q.addBindValue(ui->author->text());
    q.addBindValue(ui->price->text());
    q.addBindValue(ui->total->text());
    q.addBindValue(ui->total->text());

    if(!q.exec())
        return;
    else
        switch(QMessageBox::information(this, tr("通知"),
                              tr("新书入库成功！您要查看结果吗？!"),
                              QMessageBox::Yes|QMessageBox::No)){
        case QMessageBox::Yes:
           showUpdate();
            break;
        case QMessageBox::No:
            break;
        }
    }
    }
}

void insert::showUpdate()
{
    QTableView *v = new QTableView;
    QSqlTableModel *model = new QSqlTableModel(v);
    model->setTable("book");
    model->select();
    v->setModel(model);
    v->show();
}
void insert::on_pushButton_2_clicked()
{
   QFile file(ui->lineEdit->text());//从文本文件中读取数据
   qDebug()<<"1";
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            qDebug()<<"error !!!!";
        int i = 0;
        QSqlQuery query;
        QTextStream in(&file);
        QStringList lines = in.readAll().split("\n");
        query.prepare("insert into book(id,genre,title,publisher,year,author,price,total,remain) values(?, ?, ?, ?,?,?,?,?,?)");
        QVariantList v1, v2, v3, v4,v5,v6,v7,v8,v9;

        while(i<lines.length()){
            QString line = lines[i];
            QStringList s = line.split("\t");
            v1 << s[0];
            v2 << s[1];
            v3 << s[2];
            v4 << s[3];
            v5 << s[4];
            v6 << s[5];
            v7 << s[6];
            v8 << s[7];
            v9 << s[7];
            i++;
            QSqlQuery q;//书号, 类别, 书名, 出版社, 年份, 作者, 价格, 总藏书量, 库存

            q.prepare("select * from book where id = :id");
            q.bindValue(":id",s[0]);
            if(!q.exec())
                qDebug()<<q.lastError();
            if(q.first())
                QMessageBox::warning(NULL, tr("警告"), QString("该书号已存在！"));

             else{
                    query.addBindValue(v1);
                    query.addBindValue(v2);
                    query.addBindValue(v3);
                    query.addBindValue(v4);
                    query.addBindValue(v5);
                    query.addBindValue(v6);
                    query.addBindValue(v7);
                    query.addBindValue(v8);
                    query.addBindValue(v9);
                    if(!query.exec())
                        qDebug() << query.lastError();

                }

            }


            switch(QMessageBox::information(this, tr("通知"),
                                  tr("新书入库成功！您要查看结果吗？!"),
                                  QMessageBox::Yes|QMessageBox::No)){
            case QMessageBox::Yes:
               showUpdate();
                break;
            case QMessageBox::No:
                break;
            }

}

void insert::on_pushButton_3_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("打开"), ".", tr("文本(*.txt)"));
    if(path.length() == 0) {
            QMessageBox::warning(NULL, tr("Path"), tr("未选择任何文件"));
    } else {
            //QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
            ui->lineEdit->setText(path);
    }
}
