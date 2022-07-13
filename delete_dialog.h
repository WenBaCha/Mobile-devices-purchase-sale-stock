#ifndef DELETE_DIALOG_H
#define DELETE_DIALOG_H

#include <QDialog>

namespace Ui {
class Delete_Dialog;
}

class Delete_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_Dialog(QWidget *parent = nullptr);
    ~Delete_Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Delete_Dialog *ui;
};

#endif // DELETE_DIALOG_H
