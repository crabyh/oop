#include "querywindow.h"
#include "ui_querywindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QButtonGroup>

QueryWindow::QueryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryWindow)
{
    ui->setupUi(this);
}

QueryWindow::~QueryWindow()
{
    delete ui;

}

void QueryWindow::showAll()
{
    model = new QSqlTableModel(ui->tableView);
    model->setTable("book");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "书号");
    model->setHeaderData(1, Qt::Horizontal, "书名");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "类别");
    model->setHeaderData(5, Qt::Horizontal, "年份");
    model->setHeaderData(6, Qt::Horizontal, "价格");
    model->setHeaderData(7, Qt::Horizontal, "总量");
    model->setHeaderData(8, Qt::Horizontal, "库存");
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

}

void QueryWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);

    QString a,b;
    b=ui->lineEdit->text();
    QSqlQuery q;
    if(ui->title->isChecked()){
        if(ui->fuzzy->isChecked()){
            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where title LIKE :b order by id desc");
                }
            }
            q.bindValue(":b",'%'+b+'%');
        }
        else{
             if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where title = :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where title = :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where title = :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where title = :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where title = :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where title = :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where title = :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where title = :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where title = :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where title = :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where title = :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where title = :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where title = :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where title = :b order by id desc");
                }
            }
            q.bindValue(":b",b);
        }

            if(!q.exec())
                qDebug()<<q.lastError();
        }

    if(ui->author->isChecked()) {
        if(ui->fuzzy->isChecked()){
            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where author LIKE :b order by id desc");
                }
            }
            q.bindValue(":b",'%'+b+'%');
        }
        else{
             if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where author = :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where author = :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where author = :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where author = :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where author = :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where author = :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where author = :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where author = :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where author = :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where author = :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where author = :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where author = :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where author = :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where author = :b order by id desc");
                }
            }
            q.bindValue(":b",b);
        }

            if(!q.exec())
                qDebug()<<q.lastError();
    }
    if(ui->publisher->isChecked()) {


        if(ui->fuzzy->isChecked()){
            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where publisher LIKE :b order by id desc");
                }
            }
            q.bindValue(":b",'%'+b+'%');
        }
        else{
             if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where publisher = :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where publisher = :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where publisher = :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where publisher = :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where publisher = :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where publisher = :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where publisher = :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where publisher = :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where publisher = :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where publisher = :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where publisher = :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where publisher = :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where publisher = :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where publisher = :b order by id desc");
                }
            }
            q.bindValue(":b",b);
        }

            if(!q.exec())
                qDebug()<<q.lastError();


    }
    if(ui->genre->isChecked()) {


        if(ui->fuzzy->isChecked()){
            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where genre LIKE :b order by id desc");
                }
            }
            q.bindValue(":b",'%'+b+'%');
        }
        else{
             if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where genre = :b order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where genre = :b order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where genre = :b order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where genre = :b order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where genre = :b order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where genre = :b order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where genre = :b order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where genre = :b order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where genre = :b order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where genre = :b order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where genre = :b order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where genre = :b order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where genre = :b order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where genre = :b order by id desc");
                }
            }
            q.bindValue(":b",b);
        }

            if(!q.exec())
                qDebug()<<q.lastError();


    }
    if(ui->year->isChecked()) {
        QString min = ui->ymin->text();
        QString max = ui->ymax->text();



            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where year > :min and year < :max order by id desc");
                }
            }
            q.bindValue(":min",min);
            q.bindValue(":max",max);

            if(!q.exec())
                qDebug()<<q.lastError();
    }

    if(ui->price->isChecked()) {
        QString min = ui->pmin->text();
        QString max = ui->pmax->text();

            if(ui->asc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by title asc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by author asc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by publisher asc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by genre asc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by price asc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by year asc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by id asc");
                }
            }
            if(ui->desc->isChecked()){
                if(ui->otitle->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by title desc");
                }
                if(ui->oauthor->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by author desc");
                }
                if(ui->opublisher->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by publisher desc");
                }
                if(ui->ogenre->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by genre desc");
                }
                if(ui->oprice->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by price desc");
                }
                if(ui->oyear->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by year desc");
                }
                if(ui->oid->isChecked()){
                    q.prepare("select * from book where price > :min and price < :max order by id desc");
                }
            }
            q.bindValue(":min",min);
            q.bindValue(":max",max);

            if(!q.exec())
                qDebug()<<q.lastError();
    }
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, "书号");
    model->setHeaderData(1, Qt::Horizontal, "书名");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "类别");
    model->setHeaderData(5, Qt::Horizontal, "年份");
    model->setHeaderData(6, Qt::Horizontal, "价格");
    model->setHeaderData(7, Qt::Horizontal, "总量");
    model->setHeaderData(8, Qt::Horizontal, "库存");
    ui->tableView->setModel(model);
}

void QueryWindow::on_pushButton_2_clicked()
{
    showAll();
}

void QueryWindow::on_pushButton_3_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) // 提交所有被修改的数据到数据库中
    {
        model->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        model->database().rollback(); //提交失败，事务回滚
        QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
    }

}

void QueryWindow::deleteRow(){


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

void QueryWindow::on_pushButton_4_clicked()
{
    deleteRow();
}
