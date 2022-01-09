#include "widget.h"
#include "ui_widget.h"
#include "qpushbutton.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *button1=new QPushButton;
    button1->setText("排序");

    length = 40;
    blockH = 25;
    blockW = 15;
    data = new int [length];
    cur = 0;
    bubble = new Bubble(length,length,20,data);
   // bubble2 = new Bubble2(length,length,20,data);


    setWindowTitle("多种排序算法可视化");
    //setFixedSize(600,600);
    setGeometry(100,100,length*blockW,length*blockH+100);


    //进行信号与槽的绑定
    //connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    //connect(this,&Widget::start,bubble,&Bubble::run);
    //connect(button1,&QPushButton::click,this,&Widget::open1);

}
void Widget::paintEvent(QPaintEvent *){

    QPainter painter;
    if(data == nullptr)
        return ;
    painter.begin(this);
    for(int i = 0; i< length;i++){
        QRect rect(i*blockW,height()-data[i]*blockH,
                   blockW - 1,data[i]*blockH);
        if(i == cur){
            painter.fillRect(rect,Qt::blue);
        }else {
            painter.fillRect(rect,Qt::red);
        }
    }
    painter.end();

}

void Widget::deal(int c)
{
    cur = c;
    repaint();  //进行重绘
}
Widget::~Widget()
{
    delete [] data;
    thread->quit();     //结束子线程
    thread->wait();     //回收子线程资源
    delete ui;
}
void Widget::open_bubble()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_bubble);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_bucket()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_bucket);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_shell()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_shell);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_choice()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_choice);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_insert()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_insertion);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_merge()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_merge);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_quick()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_quick);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_radix()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_radix);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}
void Widget::open_heap()
{
    thread = new QThread(this);
    bubble->moveToThread(thread);
    connect(bubble,&Bubble::bubbleSignal,this,&Widget::deal);
    connect(this,&Widget::start,bubble,&Bubble::run_heap);
    thread->start();    //开启子线程
    emit start();       //运行子线程的goBubble函数
}



