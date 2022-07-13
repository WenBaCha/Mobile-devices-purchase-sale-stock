#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "stock.h"

namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
    void buttonFunc();
private slots:
    void on_ensure_clicked();

    void on_back_clicked();

private:
    Ui::Store *ui;
};

#endif // STORE_H
