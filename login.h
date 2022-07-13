#ifndef LOGIN_H
#define LOGIN_H
#include "widget.h"
#include <QWidget>
#include <QPainter>
#include <QString>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
   static QString getUsername();
    void checkLogin();//检查是否登录成功
    bool checkUser(QString username,QString password);
    void regist();
    void painterEvent(QPainter*);
private:
    Ui::Login *ui;
    QString user;
};

#endif // LOGIN_H
