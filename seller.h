#ifndef SELLER_H
#define SELLER_H
#include "stock.h"
#include <QWidget>

namespace Ui {
class Seller;
}

class Seller : public QWidget
{
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr);
    ~Seller();

private slots:
    void on_seller_sell_clicked();

    void on_seller_find_clicked();

    void on_seller_refresh_clicked();

private:
    Ui::Seller *ui;
    QSqlDatabase db;
};

#endif // SELLER_H
