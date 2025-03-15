#include <stdlib.h>
#define MAXQSIZE 100 // 最大队列长度

typedef int QElemType;
typedef struct
{
    QElemType *base; // 初始化的动态分配存储空间
    int front;       // 头指针，非指针，记录索引
    int rear;        // 尾指针
} SqQueue;

// 初始化一个队列
void InitSqQueue(SqQueue &sq)
{
    sq.base = new QElemType[MAXQSIZE];
    if (!sq.base)
        exit(false);
    sq.front = sq.rear = 0;
}
// 求队列长度
int QueueLength(SqQueue &sq)
{
    return ((sq.rear - sq.front + MAXQSIZE) % MAXQSIZE); //!!!循环队列长度,且循环队列中少存储一个元素
}

// 循环队列入队
void EnQueue(SqQueue &sq, QElemType e)
{
    if ((sq.rear + 1) % MAXQSIZE == sq.front)
        exit(false); // 队满
    sq.base[sq.rear] = e;
    sq.rear = (sq.rear + 1) % MAXQSIZE;
}

// 出队
void DeQueue(SqQueue &sq, QElemType &e)
{
    if (sq.front = sq.rear)
        exit(false);
    e = sq.base[sq.front];
    sq.front = (sq.front + 1) % MAXQSIZE;
}

// 取队头元素
QElemType getHead(SqQueue &sq)
{
    if (sq.front != sq.rear) // 队列不为空
    {
        return sq.base[sq.front]; //返回对头元素
    }
}
// 解决假溢出的办法是将队列变成一个循环队列