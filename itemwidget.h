#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H
//一项
#include <QWidget>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(QWidget *parent = nullptr);
    ~ItemWidget();
    void showMachineInfo(QString mNum,int price,QString factory,int present,int repertory);
    void setMachineInfo(QString mNum,int price,QString factory,int present,int repertory);
    QStringList* getMachineInfo();
    QString getMNum();
    int getPrice();
    QString getFactory();
    int getPresent();
    int getRepertory();

private:
    Ui::ItemWidget *ui;
    QString mNumber;
    int price;
    QString factory;
    int present;
    int repertory;
    const int itemNum=5;//移动设备的属性数

};

#endif // ITEMWIDGET_H
