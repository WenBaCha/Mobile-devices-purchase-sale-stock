#include "itemwidget.h"
#include "ui_itemwidget.h"
#include "stock.h"
ItemWidget::ItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
}

void ItemWidget::showMachineInfo(QString mNum,int price,QString factory,int present,int repertory){
    ui->mNumber->setText(mNum);
    ui->price->setText(QString::number(price));
    ui->factory->setText(factory);
    ui->present->setText(QString::number(present));
    ui->repertory->setText(QString::number(repertory));
}


void ItemWidget::setMachineInfo(QString mNum, int price, QString factory, int present, int repertory){
    this->mNumber=mNum;
    this->price=price;
    this->factory=factory;
    this->present=present;
    this->repertory=repertory;
}

QStringList* ItemWidget::getMachineInfo(){
    QStringList result;
    result[0]=this->mNumber;
    result[1]=QString::number(this->price);
    result[2]=this->factory;
    result[3]=QString::number(this->present);
    result[4]=QString::number(this->repertory);
    return &result;
}

QString ItemWidget::getMNum(){
    return this->mNumber;
}

int ItemWidget::getPrice(){
    return this->price;
}

QString ItemWidget::getFactory(){
    return this->factory;
}

int ItemWidget::getPresent(){
    return this->present;
}

int ItemWidget::getRepertory(){
    return this->repertory;
}
ItemWidget::~ItemWidget()
{
    delete ui;
}
