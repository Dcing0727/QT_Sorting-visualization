#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <widget.h>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();


private:
    Ui::MyWidget *ui;
    Widget *w;
    QFont font2;
    QPushButton *button1;

public slots:
    void  click_bubble();
    void  click_insert();
    void  click_heap();
    void  click_shell();
    void  click_choice();
    void  click_merge();
    void  click_bucket();
    void  click_quick();
    void  click_radix();
};

#endif // MYWIDGET_H
