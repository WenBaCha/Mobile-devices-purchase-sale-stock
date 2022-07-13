#ifndef STOCK_H
#define STOCK_H
#include "itemwidget.h"


#include <QWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardItem>
#define MAXNUM 999
#define KIND 5
namespace Ui {
class Stock;
}

class Stock : public QWidget
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();
     ItemWidget* item[MAXNUM];
     QSqlDatabase db;
private slots:
    void on_listWidget_currentTextChanged();




    void button_func();

    void on_stock_insert_clicked();

    void on_stock_watch_clicked();

    void on_stock_recorrect_clicked();

private:
    Ui::Stock *ui;
    int goodNum = 0;//当前货物种类数
//    QList<ItemWidget*> list;
//    int limitGoods=0;//最多可以存放多少货物
    QStandardItemModel *model = new QStandardItemModel();

};

#endif // STOCK_H
