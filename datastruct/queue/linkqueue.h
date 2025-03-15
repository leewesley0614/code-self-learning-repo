#define MAXQSIZE 100
#include <stdlib.h>
typedef int QElemType;
typedef struct Qnode
{
    QElemType data;
    struct Qnode *next;
} Qnode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void initLinkQueue(LinkQueue &lq)
{
    lq.front = lq.rear = new Qnode;
    if (!lq.front)
        exit(false);
    lq.front->next = nullptr;
}
// idea：从队列头节点开始，依次释放所有节点
void destroyQLinkQueue(LinkQueue &lq)
{
    while (lq.front)
    {
        Qnode *p = lq.front->next;
        delete lq.front;
        lq.front = p;
    } // lq.rear = lq.front-next; delete lq.front; lq.front = lq.rear; 直接使用rear指针
}
// 链列队操作——将元素e入队
void EnLinkQueue(LinkQueue &lq, QElemType e)
{
    Qnode *p = new Qnode;
    if (!p)
        exit(false);
    p->data = e;
    p->next = nullptr;
    lq.rear->next = p;
    lq.rear = p;
}

// 链队列操作——将元素e出对
void DeLinkQueue(LinkQueue &lq, QElemType &e)
{
    if (lq.front == lq.rear)
        exit(false);
    Qnode *p = lq.front->next;
    e = p->data;
    lq.front->next = p->next;
    if (lq.rear == p)
        lq.rear = lq.front;
    delete p;
}

// 链队列操作——求链队列的队头元素
void Gethead(LinkQueue &lq, QElemType &e)
{
    if (lq.front == lq.rear)
        exit(false);
    e = lq.front->next->data;
}