#include "store.h"
#include "ui_store.h"
#include "repertory.h"
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include<QListWidget>
#include <QDateTime>

QString mNum;
QString price;
QString factory;
QString present;
QString repertory;
QString thisTime;

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    this->setWindowTitle("入库");
    this->setFixedSize(400,300);

    buttonFunc();//按钮实现函数

}

void Store::buttonFunc(){

    //确认按钮的实现1
    connect(ui->ensure,&QAbstractButton::clicked,this,&Store::on_ensure_clicked);
    Repertory* r=new Repertory;
    //确认按钮的实现2
    connect(ui->ensure,&QAbstractButton::clicked,r,&Repertory::repertory_Store);
    r->repertory_Refresh();
}


Store::~Store()
{
    delete ui;
}

//确认按钮的实现
void Store::on_ensure_clicked()
{

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    mNum=ui->store_mNumber->text();
    price=ui->store_price->text();
    factory=ui->store_factory->text();
    present=ui->store_present->text();
    repertory=ui->store_repertory->text();
    thisTime=current_date;

}


void Store::on_back_clicked()
{
    this->close();

}

