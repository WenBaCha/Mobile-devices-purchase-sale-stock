#include "widget.h"
#include "login.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QPushButton>
#include <QtSql/QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login *l=new Login();
    l->show();
    return a.exec();
}
