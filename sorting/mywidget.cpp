#include "mywidget.h"
#include "ui_mywidget.h"
#include "QPushButton"
#include "QGridLayout"
#include "widget.h"
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //配置主场景
   //设置初始位置
    setGeometry(300,300,1300,1100);
   //设置主窗口图标
    setWindowIcon(QIcon("://image/pig.jpg"));

    setWindowTitle("多种排序可视化");

    QPushButton *Button[10];
    for(int i=0;i<10;i++)
    {
        Button[i]=new QPushButton(this);
        Button[i]->setStyleSheet("font-size:80px;color:white");

    };

    Button[0]->setText("冒泡排序");
    Button[1]->setText("插入排序");
    Button[2]->setText("堆排序");
    Button[3]->setText("希尔排序");
    Button[4]->setText("选择排序");
    Button[5]->setText("归并排序");
    Button[6]->setText("桶排序");
    Button[7]->setText("快速排序");
    Button[8]->setText("基数排序");
    Button[9]->setText("退出");

    QGridLayout *glay = new QGridLayout();
    glay->addWidget(Button[0],0,0,1,1);
    glay->addWidget(Button[1],0,1,1,1);
    glay->addWidget(Button[2],0,2,1,1);
    glay->addWidget(Button[3],1,0,1,1);
    glay->addWidget(Button[4],1,1,1,1);
    glay->addWidget(Button[5],1,2,1,1);
    glay->addWidget(Button[6],2,0,1,1);
    glay->addWidget(Button[7],2,1,1,1);
    glay->addWidget(Button[8],2,2,1,1);
    glay->addWidget(Button[9],3,1,1,2);
    setLayout(glay);

    connect(Button[0],SIGNAL(clicked(bool)), this, SLOT(click_bubble()));
    connect(Button[1],SIGNAL(clicked(bool)), this, SLOT(click_insert()));
    connect(Button[2],SIGNAL(clicked(bool)), this, SLOT(click_heap()));
    connect(Button[3],SIGNAL(clicked(bool)), this, SLOT(click_shell()));
    connect(Button[4],SIGNAL(clicked(bool)), this, SLOT(click_choice()));
    connect(Button[5],SIGNAL(clicked(bool)), this, SLOT(click_merge()));
    connect(Button[6],SIGNAL(clicked(bool)), this, SLOT(click_bucket()));
    connect(Button[7],SIGNAL(clicked(bool)), this, SLOT(click_quick()));
    connect(Button[8],SIGNAL(clicked(bool)), this, SLOT(click_radix()));
    connect(Button[9],&QPushButton::clicked,this,&MyWidget::close);
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::click_bubble()
{

    Widget *w =new Widget;
    w->setWindowTitle("冒泡排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_bubble);
    button1->show();

}
void MyWidget::click_insert()
{
    Widget *w =new Widget;
    w->setWindowTitle("插入排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_insert);
    button1->show();

}
void MyWidget::click_heap()
{
    Widget *w =new Widget;
    w->setWindowTitle("堆排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_heap);
    button1->show();
}
void MyWidget::click_merge()
{
    Widget *w =new Widget;
    w->setWindowTitle("合并排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_merge);
    button1->show();
}
void MyWidget::click_bucket()
{
    Widget *w =new Widget;
    w->setWindowTitle("桶排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_bucket);
    button1->show();
}
void MyWidget::click_quick()
{
    Widget *w =new Widget;
    w->setWindowTitle("快速排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_quick);
    button1->show();
}
void MyWidget::click_shell()
{
    Widget *w =new Widget;
    w->setWindowTitle("希尔排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_shell);
    button1->show();
}
void MyWidget::click_radix()
{
    Widget *w =new Widget;
    w->setWindowTitle("基数排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_radix);
    button1->show();
}
void MyWidget::click_choice()
{
    Widget *w =new Widget;
    w->setWindowTitle("选择排序");
    w->show();
 //  w1->setGeometry(250,150,1000,1200);
    w->setFont(font2);
    button1=new QPushButton(w);
    button1->setText("开始排序");
    //button1->setStyleSheet("border:2px groove blue;border-radius:5px;background-color:rgb(250,250,250);");
    button1->setGeometry(50,50,270,80);
    connect(button1,&QPushButton::clicked,w,&Widget::open_choice);
    button1->show();
}
