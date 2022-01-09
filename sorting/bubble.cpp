#include "bubble.h"

Bubble::Bubble(int l, int m, int mD, int *data, QObject *parent) : QObject(parent)
{
    qsrand(static_cast<uint>(QTime::currentTime().msec())); //初始化随机种子
    length = l;
    max = m;
    mDelay = mD;
    this->data = data;
    rand();
}
void Bubble::rand()
{
    if(data == nullptr)
        throw "数据不合理";
    bool flag[length];
    for(int i = 0; i < length; i++)
        flag[i] = false;
    for(int i = 0; i < length ; i++){
        while(1){
            int r = qrand()%max + 1;
            if(flag[r-1] == false){
                data[i] = r;
                flag[r-1]= true;
                break;
            }
        }
    }
}

void Bubble::goBubble()
{
    bool flag = false;  //供判断是否已经完成
    for(int i = 1; i < length && !flag; i ++){
        flag = true;
        for(int j = 0; j < length-i; j++){
            if(data[j] > data[j+1]){
                int t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
                flag = false;
            }
            bubbleSignal(j);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
    }
    for(int i = 0; i < length; i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::goInsertion()
{
    //直接插入排序
    for (int i = 1; i < length;i++) {
        int j ;
        if(data[i] < data[i - 1]){
            int temp = data[i];
            for (j = i - 1;j>= 0&&temp < data[j];j--) {
                data[j+1] = data[j];
                bubbleSignal(j);
                QThread::msleep(static_cast<unsigned int>(mDelay));
            }
            data[j + 1] = temp;
            bubbleSignal(j);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
    }
    for(int i = 0; i < length; i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::goHeap()
{
    // 初始化堆
    // length / 2 - 1是二叉树中最后一个非叶子结点的序号
    for (int i = length / 2 -1; i >= 0; i--)
    {
        heapAdjust(i,length);
        cur = i;
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    // 交换堆顶元素和最后一个元素
    for (int i = length-1; i >= 0; i--)
    {
        int temp;
        temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        heapAdjust(0,i);
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}
//重新构建大顶堆
void Bubble::heapAdjust(int i, int len)
{
    int temp = data[i];
    for(int j = 2*i+1;j <len; j=j*2+1){
        if(j < len-1 && data[j] < data[j + 1]){
            ++j;
        }
        if(temp >= data[j])
            break;
        data[i] = data[j];
        i = j;
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    data[i] = temp;
}

void Bubble::goShell()
{
    int increasement = length;
    int i, j, k;
    do
    {
        // 确定分组的增量
        increasement = increasement / 3 + 1;
        for (i = 0; i < increasement; i++)
        {
            for (j = i + increasement; j < length; j += increasement)
            {//这里跟插入排序的思想很像，通过挪位来插入值
                if (data[j] < data[j - increasement])
                {
                    int temp = data[j];
                    for (k = j - increasement; k >= 0 && temp < data[k]; k -= increasement)
                    {
                        data[k + increasement] = data[k];
                        bubbleSignal(k);
                        QThread::msleep(static_cast<unsigned int>(mDelay));
                    }
                    data[k + increasement] = temp;

                }
            }
        }
    } while (increasement > 1);
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::goChoice()
{
    for (int i = 0;i < length; i++) {   //先进行整体循环遍历
        int index = i;                  //当前比较的位子
        for (int j = i+1;j < length; j++) {
            if(data[index] > data[j]){  //在余下的数找到其最小的数
                index = j;
                bubbleSignal(j);
                QThread::msleep(static_cast<unsigned int>(mDelay));
            }
        }
        if(index == i)  //没有找到，即表示当前数是余下数的最小数
            continue;
        else {          //找到，即将当前位子的数与找到的数进行交换
            int temp = data[index];
            data[index] = data[i];
            data[i] = temp;
        }
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}
/*举个栗子 有数据 12，9，11，13，5，7
 * 先进行递归将数组分为长度尽可能相等的两部分
 *      第一次递归    第二次递归  第三次递归
 *      12，9，11 -->  12,9           经过mergeSort递归到底
 *                          --> 9,12  在merge中进行排序
 *                     11            返回上一层递归中，向右递归到底
 *                          --> 9,11,12     在merge中进行排序
 *      13，5，7 --->  13,5 --> 5,13 --> 5,7,13   同理上
 *      -->5,7,9,11,12,13           得到最终排序
 *  最终会在动画看到先是排好一个小山峰（9，11，12）然后紧接着又排好一个小山峰（5,7,13）
 *  然后俩个小山峰进行在merge中进行归并就得出了大山峰（5,7,9,11,12,13）
 */


void Bubble::goMerge()
{
    mergeSort(0,length-1);
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}
//将数组分为尽可能相等的俩个部分
void Bubble::mergeSort(int l, int r)
{
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}
//对于俩个被分开的两个部分进行整个归并排序
void Bubble::merge(int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r - m;
    int L[n1],R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = data[l+i];       //存数组l到m之间的数据
    }
    for(int i = 0; i < n2; i++){
        R[i] = data[m + 1 + i]; //存数组m+1到r之间的数据
    }
    int k = l,i = 0, j = 0;
    while(i < n1 && j < n2){    //将两个部分进行排序
        if(L[i] <= R[j]){
            data[k] = L[i];
            i++;
        }
        else{
            data[k] = R[j];
            j++;
        }
        k++;
        bubbleSignal(k);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    while(i < n1){              //将L中剩余的值放入data中
        data[k] = L[i];
        i ++;
        k ++;
        bubbleSignal(k);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
    while(j < n2){
        data[k] = R[j];         //将R中剩余的值放入data中
        j ++;
        k ++;
        bubbleSignal(k);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::goBucket()
{
    int max = data[0];
    for(int i = 1 ;i < length; i ++){
        if(data[i] > max)
            max = data[i];
    }
    max ++;                         //加一是为了防止数组越界
    QVector<int> b[10];             //假设放十个桶，这个可以自定义
    for (int i = 0; i < length; i++) {
        int bi = 10*data[i]/max;
        b[bi].push_back(data[i]);   //然后将数据以10为间隔放置数据
    }

    int c = 0,len =0;   //c用来表示新放入数组的位子，len表示经历各个桶的累长度
    for(int i = 0; i < 10; i ++){   //将data的数据进行重新放入，方便动图观看
        for(int j = 0; j < b[i].size(); j++){
            data[c++] = b[i].at(j);
        }
    }
    c = 0;
    for(int i = 0; i < 10; i ++){
        //这里本想使用sort库来实现各个桶内的排序方便偷个懒的
        //可是那样就不好动图表现了，就用了直接插入排序来代替了，好像也不是很好看
        //std::sort(b[i].begin(),b[i].end());
        for(int j = 1+len; j < b[i].size()+len; j++){
            //直接插入排序
            int k;
            if(data[j] < data[j - 1]){
                int temp = data[j];
                for (k = j - 1;k>= len&&temp < data[k];k--) {
                    data[k+1] = data[k];
                    bubbleSignal(k);
                    QThread::msleep(static_cast<unsigned int>(mDelay));
                }
                data[k+1] = temp;
//                bubbleSignal(k + len);
//                QThread::msleep(static_cast<unsigned int>(mDelay));
            }
        }
        len += b[i].size();
    }
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::goQuick()
{
    quickSort(0,length-1);      //进行快排
    for(int i = 0; i < length;i++){
        bubbleSignal(i);
        QThread::msleep(static_cast<unsigned int>(mDelay));
    }
}

void Bubble::quickSort(int l, int r)
{
    if(l < r){
        int mid = quickQartition(l,r);  //得到分割数
        quickSort(l,mid);       //再次进行快排
        quickSort(mid+1,r);
    }
}
//将数组的最左边的数据为分割数，将比分割数大的数放在分割数的右边，小的放在左边
//返回分割数最后所在的位子
int Bubble::quickQartition(int l, int r)
{
    int t = data[l];    //t为分割数
    while(l < r){
        while(l < r && data[r] >= t)//如果最右边的数大于分割数，则寻次右边的数进行比较
            r --;
        quickSwap(l,r); //如果分割数比右边的数要大，则将俩者交换位子
        while(l < r && data[l] <= t)//同上
            l ++;
        quickSwap(l,r);
    }
    return l;
}

void Bubble::quickSwap(int one, int two)
{
    int temp = data[one];
    data[one] = data[two];
    data[two] = temp;
    bubbleSignal(one);
    QThread::msleep(static_cast<unsigned int>(mDelay));
}

void Bubble::goRadix()
{
    int max = data[0];      //寻找最大值，由此得知所需的位数
    for(int i = 1 ; i < length; i++){
        if(data[i] > max)
            max = data[i];
    }
    //以个、十、百....的位的数目来遍历
    for (int exp = 1; max/exp > 0; exp *= 10) {
        int output[length];
        int count[10] = {0};
        for(int i = 0; i < length; i++){//得到每个位数上的数字的个数
            count[(data[i]/exp)%10]++;  //例如在{1,2,11,13,4}个位为一的有2个，个位为2的有1，...
        }
        //然后将所得到的所有位数进行累加求和，方便判断是在output[]的那个位子上
        for(int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        for(int i = length -1; i >= 0; i--){
            output[count[(data[i]/exp)%10] - 1]= data[i];
            count[(data[i]/exp)%10] --;
            bubbleSignal(i);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
        for(int i = 0; i < length; i++){
            data[i] = output[i];    //将此趟排序好的数据赋值回去
            bubbleSignal(i);
            QThread::msleep(static_cast<unsigned int>(mDelay));
        }
    }
}



 void Bubble::run_bubble()
{
     rand();
     goBubble();
}
void Bubble::run_bucket()
{
    rand();
    goBucket();

}
void Bubble::run_heap()
{
    rand();
    goHeap();

}
void Bubble::run_insertion()
{
    rand();
    goInsertion();
}
void Bubble::run_shell()
{
    rand();
    goShell();

}
void Bubble::run_quick()
{
    rand();
    goQuick();

}
void Bubble::run_radix()
{
    rand();
    goQuick();

}
void Bubble::run_merge()
{
    rand();
    goMerge();
}
void Bubble::run_choice()
{
    rand();
    goChoice();
}


