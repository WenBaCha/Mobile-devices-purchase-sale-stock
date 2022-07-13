#ifndef RIGST_H
#define RIGST_H

#include <QWidget>

namespace Ui {
class Rigst;
}

class Rigst : public QWidget
{
    Q_OBJECT

public:
    explicit Rigst(QWidget *parent = nullptr);
    ~Rigst();
    bool submitInfo();
private:
    Ui::Rigst *ui;
};

#endif // RIGST_H
