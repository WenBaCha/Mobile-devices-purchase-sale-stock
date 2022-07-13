#include "repertory.h"
#include "itemwidget.h"
#include "ui_repertory.h"
#include "widget.h"
#include "store.h"
#include "delete_dialog.h"
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include<QListWidget>

extern QString mNum;
extern QString price;
extern QString factory;
extern QString present;
extern QString repertory;
extern QString thisTime;
extern bool isDelete;
QString mNumber;//传入确认对话框的全局变量
Repertory::Repertory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Repertory)
{
    ui->setupUi(this);
    this->setWindowTitle("库存页面");
    this->setFixedSize(700,400);
    ui->repertory_listWidget->setFixedSize(580,400);

    init_Item();//初始化ItemWIdget
    init_goods();//初始化货物
    button_Func();//实现所有按钮
}

Repertory::~Repertory()
{
    delete ui;
}


//入库按钮的槽函数（点击入库后执行的函数）
void Repertory::on_repertory_add_clicked()
{
    //关闭本页面
    this->close();
    //新建一个入库页面对象
    Store* s=new Store;
    //显示入库页面
    s->show();
}

//入库页面中点击确认按钮的槽函数
void Repertory::repertory_Store(){

    QSqlQuery *q=new QSqlQuery;

    //先查询数据库中是否存在与欲入库的数据相同的行
    qDebug()<<"mNum is"<<mNum;
    QString select=QString("select * from repertory where mNumber='"+mNum+"';");

    //如果查询失败，则向其中插入入库的数据
    if(!q->exec(select)){
        qDebug()<<"repertory_Store select failed";
        QString insert=QString("insert into repertory(mNumber,price,factory,present,repertory)"
                               " values('"+mNum+"',"+price+",'"+factory+"',"+present+","+repertory+");");
        //如插入失败
        if(!q->exec(insert))qDebug()<<"repertory_Store insert into repertory failed";

    //查询成功,更新数据库，增加对应库存
    }else{
        qDebug()<<"success to select";

        QString update=QString("update repertory "
                               "set repertory="+repertory+
                               " where mNumber='"+mNum+"';");
        if(!q->exec(update)){
            qDebug()<<"repertory_Store update failed";
        }else{
            qDebug()<<"repertory_Store update succeed";
        }

    }

    qDebug()<<"test successfuly";
    QString sqlShow=QString("select * from repertory;");
    if(!q->exec(sqlShow)){
        qDebug()<<"fail to show the data"<<db.lastError();
    }

    int sum=0;
    while(q->next()){
        QString mNumber=q->value("mNumber").toString();
        int price=q->value("price").toInt();
        QString factory=q->value("factory").toString();
        int present=q->value("present").toInt();
        int repertory=q->value("repertory").toInt();

        ItemWidget* iw =new ItemWidget;
        iw->showMachineInfo(mNumber,price,factory,present,repertory);
        QListWidgetItem* item=new QListWidgetItem;
        item->setSizeHint(QSize(562,34));
        ui->repertory_listWidget->addItem(item);
        ui->repertory_listWidget->setItemWidget(item,iw);
        sum+=iw->getRepertory();
    }
}

//刷新库存页面
void Repertory::repertory_Refresh(){
    this->close();
    Repertory* r= new Repertory;
    r->show();
}

//从数据库中获取设备信息并输出到页面上
void Repertory::init_goods(){
    QStringList drivers=QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug()<<driver;
    }
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

    QString insert=QString("insert into repertory(mNumber,price,factory,present,repertory)"
                           " values('"+mNum+"',"+price+",'"+factory+"',"+present+","+repertory+");");
    if(!query.exec(insert)){
        qDebug()<<"query insert unsuccessfully";
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

            this->item[sum]->showMachineInfo(mNumber,price,factory,present,repertory);
            QListWidgetItem* item=new QListWidgetItem;
            item->setSizeHint(QSize(562,34));
            ui->repertory_listWidget->addItem(item);
            ui->repertory_listWidget->setItemWidget(item,this->item[sum]);
            sum++;
    }


    ui->sum->setText("设备种类:"+QString::number(sum));
}

//封装所有按钮的功能
void Repertory::button_Func(){
    //返回按钮的实现
    connect(ui->repertory_back,&QAbstractButton::clicked,[=](){
        this->close();
        Widget* w=new Widget;
        w->show();
    });

    //刷新按钮的实现
    connect(ui->repertory_refresh,&QAbstractButton::clicked,this,&Repertory::repertory_Refresh);

    //删除按钮的实现
    connect(ui->repretory_delete,&QAbstractButton::clicked,this,&Repertory::on_repretory_delete_clicked);



}

//查找设备按钮槽函数
void Repertory::on_repertory_find_clicked()
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

                    this->item[i]->showMachineInfo(mNumber,price,factory,present,repertory);
                    QListWidgetItem* item=new QListWidgetItem;
                    item->setSizeHint(QSize(562,34));
                    ui->repertory_listWidget->addItem(item);
                    ui->repertory_listWidget->setItemWidget(item,this->item[i]);
                    this->item[i]->setFocus();
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

//初始化ItemWidget数组
void Repertory::init_Item(){
    int i=0;
    while(i!=MAXNUM - 1){
        this->item[i]=new ItemWidget;
        i++;
    }
}


//删除按钮的实现
void Repertory::on_repretory_delete_clicked()
{
    QSqlQuery q;
    //如果输入框无文本就点击删除
    if(ui->find_input->text()==""){
        QMessageBox::information(this,"提示","请先输入设备型号！");
        return;

    //有文本
    }else{
        mNumber=ui->find_input->text();

        qDebug()<<"delete is";
        qDebug()<<isDelete;

            QString sqlDelete=QString("delete from repertory where mNumber='"+ui->find_input->text()+"';");
            if(!q.exec(sqlDelete)){
                qDebug()<<"delete failed";
                QMessageBox::information(this,"提示","删除失败");
            }
            else{
                qDebug()<<"delete successfully";
                QMessageBox::information(this,"提示","删除成功");
            }


}
}


void Repertory::on_repertory_alter_clicked()
{

}

