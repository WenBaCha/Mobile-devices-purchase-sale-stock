#include "rigst.h"
#include "ui_rigst.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

Rigst::Rigst(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rigst)
{
    ui->setupUi(this);
    this->setWindowTitle("移动设备进销存管理系统注册");
    this->setFixedSize(415,320);
    this->setStyleSheet("background:url(://res/purpleblue.JPG) no repeat/cover;");
    connect(ui->ensure,&QAbstractButton::clicked,this,&Rigst::submitInfo);

}

bool Rigst::submitInfo(){
    QString username=ui->regist_username->text();
    QString psd1=ui->regist_password->text();
    QString psd2=ui->regist_epassword->text();
    if(username==""&&psd1==""&&psd2==""){
        QMessageBox::information(this,"提示","请完整填写表单！");
    }
    else if(psd1!=psd2){
        QMessageBox::information(this,"提示","两次输入密码不一致，请检查");
    }else{
        QFile file("D:\\QTProgram\\Moblie\\userData.txt");

        if(file.open(QIODevice::WriteOnly|QIODevice::Append)){
            QTextStream out(&file);
            out<<username;
            out<<",";
            out<<psd1<< '\n';
            QMessageBox::information(this,"提示","注册成功！");
        }else{
            QMessageBox::information(this,"提示","文件打开失败！");
        }
        file.close();
    }
}

Rigst::~Rigst()
{
    delete ui;
}
