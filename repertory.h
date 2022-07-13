#ifndef REPERTORY_H
#define REPERTORY_H
#include"itemwidget.h"
#include <QWidget>
#include <QWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
namespace Ui {
class Repertory;
}
#define MAXNUM 999
class Repertory : public QWidget
{
    Q_OBJECT

public:
    explicit Repertory(QWidget *parent = nullptr);
    ~Repertory();
    void repertory_Store();
    void repertory_Refresh();
    void init_goods();
    void button_Func();//按钮的连接函数放置在其中，起到封装的作用，并无实际意义
    void init_Item();
    ItemWidget* item[MAXNUM];
private slots:
    void on_repertory_add_clicked();

    void on_repertory_find_clicked();

    void on_repretory_delete_clicked();

    void on_repertory_alter_clicked();

private:
    Ui::Repertory *ui;
    QSqlDatabase db;

};

#endif // REPERTORY_H
