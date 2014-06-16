#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    MainWindow::close();

}

void MainWindow::on_pushButton_2_clicked()
{
    ins.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    query.show();
}

void MainWindow::on_pushButton_4_clicked()
{
    borrow.show();
}

void MainWindow::on_pushButton_5_clicked()
{
    manager.show();
}

void MainWindow::on_pushButton_6_clicked()
{
    card.show();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("关于"),tr("欢迎使用！这是由浙江大学计算机科学与技术专业的毕婷宇设计的图书管理系统。包括功能：查询书籍、图书入库、借还书、图书证管理、管理员增删等。"));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
