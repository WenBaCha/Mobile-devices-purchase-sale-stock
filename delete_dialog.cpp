#include "delete_dialog.h"
#include "ui_delete_dialog.h"
#include "repertory.h"
#include <QMessageBox>
//查看库存-》删除-》确认删除页面
extern QString mNumber;
bool isDelete=false;
Delete_Dialog::Delete_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_Dialog)
{
    ui->setupUi(this);
    QString text="你确定要删除型号为："+mNumber+"的设备吗";
    ui->text_ensure->setText(text);
    connect(ui->pushButton,&QAbstractButton::clicked,this,&Delete_Dialog::on_pushButton_clicked);
    connect(ui->pushButton_2,&QAbstractButton::clicked,this,&Delete_Dialog::on_pushButton_2_clicked);
}

Delete_Dialog::~Delete_Dialog()
{
    delete ui;
}

//删除按钮
void Delete_Dialog::on_pushButton_clicked()
{
    isDelete=true;
    this->close();

}

//返回按钮
void Delete_Dialog::on_pushButton_2_clicked()
{
    this->close();
}

