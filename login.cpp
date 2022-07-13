#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include "rigst.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QPixmap>


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->user=ui->username->text();
    this->setWindowTitle("移动设备进销存管理系统登录");
    this->setFixedSize(415,320);
    this->setStyleSheet("background:url(://res/purpleblue.JPG) /cover;");
    connect(ui->login,&QPushButton::clicked,this,&Login::checkLogin);
    connect(ui->regist,&QPushButton::clicked,this,&Login::regist);


}

void Login::checkLogin(){
    QString username=ui->username->text();
    QString password=ui->password->text();
    if(checkUser(username,password)){
        Widget *w=new Widget;
        this->close();
        w->show();
        QMessageBox::information(this,"提示","登录成功！");
    }else{
        QMessageBox::information(this,"提示","用户名或密码错误！");
    }

    qDebug()<<username;
    qDebug()<<password;
    update();
}

bool Login::checkUser(QString username,QString password){
    bool result=false;
    QFile file("D:\\QTProgram\\Moblie\\userData.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            int i=0;
            QStringList index=in.readLine().split(',');
            if(index[i]==username&&index[i+1]==password){
                result=true;
                break;
            }
            i++;
        }
        file.close();
    }
    return result;
}

//注册按钮的实现
void Login:: regist(){
    Rigst* rigst=new Rigst;
    rigst->show();
}

void Login::painterEvent(QPainter*){

    QPainter painter(this);
    QPixmap pixmap = QPixmap("://res/purpleblue.JPG");/*.scaled(this->size());*/
    painter.drawPixmap(0,0,width(),height(),pixmap);
    painter.drawPixmap(this->rect(), pixmap);
    update();
}

QString Login::getUsername(){
    Login l;
    return l.user;
}

Login::~Login()
{
    delete ui;
}
