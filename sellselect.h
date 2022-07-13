#ifndef SELLSELECT_H
#define SELLSELECT_H
#include <QWidget>
#include <QWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QWidget>

namespace Ui {
class SellSelect;
}

class SellSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SellSelect(QWidget *parent = nullptr);
    ~SellSelect();
private slots:
    void on_ensure_clicked();

    void on_back_clicked();

private:
    Ui::SellSelect *ui;
    QSqlDatabase db;
};

#endif // SELLSELECT_H
