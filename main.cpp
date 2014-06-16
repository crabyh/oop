#include "mainwindow.h"
#include "logdialog.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LogDialog log;
    abcdb();
    if (log.exec() == QDialog::Accepted)
        {
           w.show();
           return a.exec();
        }
    else return 0;
    return a.exec();
}
