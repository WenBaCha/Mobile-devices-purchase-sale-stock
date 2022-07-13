#include "aboutus.h"
#include "ui_aboutus.h"
#include "widget.h"
#include <QAbstractButton>
AboutUs::AboutUs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutUs)
{
    ui->setupUi(this);
    ui->textEdit->setText("移动设备进销存管理系统是由西华大学数据结构与算法综合设计移动设备进销存小组全体组员开发完成，是一个能够让管理者更加方便地对移动设备进货出货入库出库等活动进行记录和管理的软件"
                          "");
    connect(ui->back,&QAbstractButton::clicked,[=](){
        this->close();
        Widget* w=new Widget;
        w->show();
    });
}

AboutUs::~AboutUs()
{
    delete ui;
}
