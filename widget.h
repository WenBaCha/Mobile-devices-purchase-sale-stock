#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

static bool isShow=false;

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static void initShow(bool show);
    static bool getShow();
    static void drawWindow();
private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
