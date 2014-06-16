#include "database.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>



QSqlError abcdb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("oop");
    db.setUserName("root");
    db.setPassword("123456");
    qDebug() << QSqlDatabase::drivers();
    if (!db.open()){
        qDebug()<<"can't open database";
        return db.lastError();
    }
    else qDebug() << "open";

    QSqlQuery q;
    q.exec(QString("drop table record"));
    q.exec(QString("drop table book"));
    q.exec(QString("drop table manager"));
    q.exec(QString("drop table card"));

    if(q.exec(QString("create table book (id int primary key, title varchar(50), author varchar(20), publisher varchar(30),genre varchar(20), year int, price decimal(7,2), total int, remain int)")))
        //书号，书名，作者，出版社，类别，年份，价格，总量，剩余
    qDebug()<<"book created";
    else qDebug()<<q.lastError();

   if(q.exec(QLatin1String("create table manager(id varchar(20), password varchar(20),name varchar(20), phone char(11),primary key (id))")))
        //管理员ID, 密码， 姓名， 联系方式
     qDebug()<<"manager created";
   else qDebug()<<q.lastError();

   if(q.exec(QLatin1String("create table card(id int primary key,name varchar(20),department varchar(30),usrgroup varchar(10))")))
       //卡号, 姓名, 单位, 类别 (教师 学生等)
       qDebug()<<"card created";
   else qDebug()<<q.lastError();

    if(q.exec(QLatin1String("create table record(cid int,bid int,btime date,rtime date,mid varchar(20),foreign key (bid) references book(id),foreign key (cid) references card(id),foreign key (mid) references manager(id))")))
        //卡号, 书号,借期, 还期， 经手人（管理员ID）
        qDebug()<<"record created";
   else qDebug()<<q.lastError();

   if(q.exec("insert into book(id,title,author,publisher,genre,year,price,total,remain) values(1,'1984','George Orwell','Signet Classic','Literature',1950,11.86,10,3)"))
     qDebug()<<"book inserted";
   else qDebug()<<q.lastError();
   if(q.exec("insert into book(id,title,author,publisher,genre,year,price,total,remain) values(2,'A Brief History of Time','Stephen Hawking','Bantam','Science',1998,19.89,10,3)"))
     qDebug()<<"book inserted";
   else
       qDebug()<<q.lastError();

   q.exec(QLatin1String("insert into manager values('3120100964','1234','Hanyu Yang','18868122668')"));
   q.exec(QLatin1String("insert into card values ('1','Hanyu Yang','CS','Student')"));//卡号, 姓名, 单位, 类别 (教师 学生等)
   if(!q.exec(QLatin1String("insert into record values('1','1','2014-04-19','2014-05-19','3120100964')")))
       qDebug()<<q.lastError();

    return QSqlError();
}
