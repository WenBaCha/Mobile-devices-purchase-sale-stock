#include "seller.h"
#include "ui_seller.h"
#include "repertory.h"
#include "stock.h"
#include "itemwidget.h"
#include "sellselect.h"
#include "widget.h"
#include <QStringList>
#include <QDebug>
#include<QListWidget>
#include <QMessageBox>
Seller::Seller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
    this->setWindowTitle("销售商品页面");
    this->setFixedSize(700,400);
    ui->seller_listWidget->setFixedSize(580,400);

    //[1] 根据数据库类型来连接数据
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("stock.db");
    //[2] 打开数据库
    if(!db.open()){
        qDebug()<<"open failed"<<db.lastError();
    }else{
        qDebug()<<"open success";
    }

    //[3]根据需求创建数据库所需表

    QSqlQuery query;
//    if(query.exec("DROP TABLE IF EXISTS 'repertory';")){
//        qDebug()<<"delete successfully";
//    }

//    QString sqlCreateTable=QString("create table repertory(mNumber varchar(12) primary key,"
//                                   "price int,"
//                                   "factory varchar(12),"
//                                   "present int,"
//                                   "repertory int);");

//    if(!query.exec(sqlCreateTable)){
//        qDebug()<<"fail to create the table "<<db.lastError();
//    }

    //插入数据操作
    QString sqlInsert=QString("insert into repertory(mNumber,price,factory,present,repertory)"
                              "values('A001',1299,'huawei',100,0);");
    if(!query.exec(sqlInsert)){
        qDebug()<<"fail to insert into data"<<db.lastError();
    }

    QString sqlShow=QString("select * from repertory;");
    if(!query.exec(sqlShow)){
        qDebug()<<"fail to show the data"<<db.lastError();
    }

    int sum=0;
    while(query.next()){
        QString mNumber=query.value("mNumber").toString();
        int price=query.value("price").toInt();
        QString factory=query.value("factory").toString();
        int present=query.value("present").toInt();
        int repertory=query.value("repertory").toInt();

        ItemWidget* iw =new ItemWidget;
        iw->showMachineInfo(mNumber,price,factory,present,repertory);
        QListWidgetItem* item=new QListWidgetItem;
        item->setSizeHint(QSize(562,34));
        ui->seller_listWidget->addItem(item);
        ui->seller_listWidget->setItemWidget(item,iw);
        sum++;
    }
    ui->sum->setText("总库存:"+QString::number(sum));
    connect(ui->seller_back,&QAbstractButton::clicked,[=](){
        this->close();
        Widget* w=new Widget;
        w->show();
    });

    connect(ui->seller_sell,&QAbstractButton::clicked,this,&Seller::on_seller_sell_clicked);
    connect(ui->seller_find,&QAbstractButton::clicked,this,&Seller::on_seller_find_clicked);
    connect(ui->seller_refresh,&QAbstractButton::clicked,this,&Seller::on_seller_refresh_clicked);
}

Seller::~Seller()
{
    delete ui;
}

//销售按钮的实现
void Seller::on_seller_sell_clicked()
{     
            this->close();
            SellSelect* s=new SellSelect;
            s->show();
}

//查询按钮的实现
void Seller::on_seller_find_clicked()
{
    //如果输入框无文本就点击查询
    if(ui->find_input->text()==""){
        QMessageBox::information(this,"提示","请先输入设备型号！");
        return;

    //有文本
    }else{

        QSqlQuery query;
        //查找数据库中是否有该型号的设备
        QString select=QString("select * from repertory;");

        //查询失败（出了故障，而非没有该数据）
        if(!query.exec(select)){
            qDebug()<<"on_repertory_find_clicked() faile to select";


        //查找到了设备
        }else{

            int i=0;
            while(query.next()){
                if(ui->find_input->text()==query.value("mNumber").toString()){

                    QString mNumber=query.value("mNumber").toString();
                    int price=query.value("price").toInt();
                    QString factory=query.value("factory").toString();
                    int present=query.value("present").toInt();
                    int repertory=query.value("repertory").toInt();
                    ItemWidget* iw=new ItemWidget;
                    iw->showMachineInfo(mNumber,price,factory,present,repertory);
                    QListWidgetItem* item=new QListWidgetItem;
                    item->setSizeHint(QSize(562,34));
                    ui->seller_listWidget->addItem(item);
                    ui->seller_listWidget->setItemWidget(item,iw);
                    iw->setFocus();
                    i++;
                }

            }

            if(i==0){
                QMessageBox::information(this,"提示","未找到该设备！");
                return;
            }

        }
    }
}

//刷新按钮的实现
void Seller::on_seller_refresh_clicked()
{
    this->close();
    Seller*s=new Seller;
    s->show();
}

