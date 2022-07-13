#include "widget.h"
#include "repertory.h"
#include "login.h"
#include "stock.h"
#include "ui_widget.h"
#include "seller.h"
#include "aboutus.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("移动设备进销存管理系统");
    this->setFixedSize(415,320);
    this->setStyleSheet("background:url(://res/purpleblue.JPG) / cover;");
    connect(ui->sell,&QAbstractButton::clicked,[=](){
        Seller *s=new Seller;
        this->close();
        s->show();
    });

    connect(ui->stock,&QAbstractButton::clicked,[=](){
        Stock *s=new Stock;
        this->close();
        s->show();
    });

    connect(ui->watch,&QAbstractButton::clicked,[=](){
        this->close();
        Repertory *r=new Repertory;
        r->show();
    });

    connect(ui->backto_login,&QAbstractButton::clicked,[=](){
        this->close();
        Login*l =new Login;
        l->show();
    });

    connect(ui->about_us,&QAbstractButton::clicked,[=](){
        this->close();
        AboutUs* au=new AboutUs;
        au->show();
    });
}

Widget::~Widget()
{
    delete ui;
}

