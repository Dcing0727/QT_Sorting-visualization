#ifndef BUBBLE_H
#define BUBBLE_H

#include <QObject>
#include <QThread>
#include <QTime>
#include <QVector>
#include <QtAlgorithms>
class Bubble : public QObject
{
    Q_OBJECT
public:
    explicit Bubble(int l,int m,int mD,int *data,QObject *parent = nullptr);
    void rand();                //随机产生数据

    void goBubble();            //处理冒泡排序算法--1
    void goInsertion();         //处理插入排序算法--2
    void goHeap();              //堆排序--3
    void heapAdjust(int i, int len);
    void goShell();             //希尔排序--4
    void goChoice();            //选择排序--5
    void goMerge();             //归并排序--6
    void mergeSort(int l,int r);
    void merge(int l,int m, int r);
    void goBucket();            //桶排序--7
    void goQuick();             //快速排序--8
    void quickSort(int l,int r);
    int quickQartition(int l,int r);
    void quickSwap(int one,int two);
    void goRadix();             //基数排序--9
    void run_bubble();
    void run_bucket();
    void run_shell();
    void run_heap();
    void run_quick();
    void run_merge();
    void run_insertion();
    void run_radix();
    void run_choice();
signals:
    void bubbleSignal(int cur); //发送当前排序的位子
private:
    int length;     //数组的长度
    int *data;      //数组
    int max;        //单个数据的最大值
    int cur;        //排序当前处理的位置
    int mDelay;     //延时时间，方便动态展示
};


#endif // BUBBLE_H
