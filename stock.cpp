#include "stock.h"
#include "widget.h"
#include "itemwidget.h"
#include "ui_stock.h"
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include<QListWidget>
#include <QStandardItemModel>
#define StockNum 99

int numFac;//厂商个数
//进货页面
Stock::Stock(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Stock)
{
    ui->setupUi(this);
    this->setFixedSize(250,400);
    this->setWindowTitle("商家管理界面");

    button_func();//各个按钮的实现



    model->setColumnCount(1);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("company name"));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    model->setItem(numFac++,0,new QStandardItem("xiaomi"));


}

//各个按钮功能的实现
void Stock::button_func(){
    //退出按钮
    connect(ui->stock_back,&QAbstractButton::clicked,[=](){
        this->close();
        numFac=0;
        Widget *w=new Widget;
        w->show();
    });

    //录入按钮的实现
    connect(ui->stock_insert,&QAbstractButton::clicked,this,&Stock::on_stock_insert_clicked);


    //进货按钮

}

//查询设备槽函数(有问题待解决)
void Stock::on_listWidget_currentTextChanged()
{
    QSqlQuery q;//选择型号为输入框输入的设备
    QString sqlSelect=QString("select * from sck;");

    if(!q.exec(sqlSelect)){
        qDebug()<<"fail to select";
    }

    int i=0;
//    while(q.next()){
//        if(ui->find_input->text()==q.value("mNumber").toString()){

//            QString mNumber=q.value("mNumber").toString();
//            int price=q.value("price").toInt();
//            QString factory=q.value("factory").toString();
//            int present=q.value("present").toInt();
//            int repertory=q.value("repertory").toInt();

//            this->item[i]->showMachineInfo(mNumber,price,factory,present,repertory);
//            QListWidgetItem* item=new QListWidgetItem;
//            item->setSizeHint(QSize(562,34));
//            ui->listWidget->clear();
//            ui->listWidget->addItem(item);
//            ui->listWidget->setItemWidget(item,this->item[i]);
//            i++;
//        }
//        i=0;
//    }

}






Stock::~Stock()
{
    delete ui;
}

//插入按钮的实现
void Stock::on_stock_insert_clicked()
{
    model->setItem(numFac++,0,new QStandardItem(ui->name_input->text()));
}

//查询按钮的实现
void Stock::on_stock_watch_clicked()
{
    if(ui->name_input->text()==""){
        QMessageBox::information(this,"提示","请先输入厂商姓名");
        return;
    }else{
        QMessageBox::information(this,"提示","找到了"+ui->name_input->text());
    }

}

//修改按钮
void Stock::on_stock_recorrect_clicked()
{
    //将tableView设置为可修改
    ui->tableView->setAcceptDrops(true);
}

