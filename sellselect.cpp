#include "sellselect.h"
#include "ui_sellselect.h"
//点击销售->销售按钮后出现的界面
#include "seller.h"
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include<QListWidget>

SellSelect::SellSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("销售商品");
    this->setFixedSize(400,300);
    connect(ui->ensure,&QAbstractButton::clicked,this,&SellSelect::on_ensure_clicked);


}

SellSelect::~SellSelect()
{
    delete ui;
}

//确认销售按钮
void SellSelect::on_ensure_clicked()
{
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

    QSqlQuery q;
    QString select=QString("select * from repertory where mNumber='"+ui->mNumber->text()+"';");
    if(!q.exec(select)){
        qDebug()<<"SellSelect::on_ensure_clicked select failed";
    }

    QString mNumber=ui->mNumber->text();
    QString goodsNum=ui->goodsNum->text();
    QString changeNum;
    if(q.next()){
        changeNum=QString::number(q.value("repertory").toInt()-goodsNum.toInt());
    }

    if(q.value("repertory").toInt()<=0){
        QMessageBox::information(this,"提示","该商品已售完！请进货！");
        QString update=QString("update repertory "
                       "set repertory=0"
                       " where mNumber='"+ui->mNumber->text()+"';");
        q.exec(update);
        return ;
    }else{
        QString update=QString("update repertory "
                       "set repertory="+changeNum
                       +" where mNumber='"+ui->mNumber->text()+"';");
        if(q.exec(update)){
        qDebug()<<"SellerSelect::on_ensure_clicked failed to update";
        this->close();
        QMessageBox::information(this,"提示","销售成功");

        }else{
            QMessageBox::information(this,"提示","销售失败！"+changeNum+","+goodsNum+","+q.value("repertory").toString());
            return ;
        }
    }
}


void SellSelect::on_back_clicked()
{
    this->close();
    Seller* s= new Seller;
    s->show();
}

