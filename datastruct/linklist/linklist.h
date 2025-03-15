#define OK 1;
#define ERROR 0;
#include <iostream>
typedef int Item;
typedef bool Status;
// define the linklist structure
typedef struct Lnode
{
    Item data;
    Lnode *next;
} Lnode, *LinkList;

// Initialize a linklist
Status l_listInit(LinkList &l)
{
    l->next = nullptr;
    return OK;
}
// Destroy a linklist
Status l_listDestroy(LinkList &l)
{
    Lnode *p;
    while (l)
    {
        p = l;
        l = l->next;
        delete p;
    }
    return OK;
}
// Clear a linklist
Status l_listClear(LinkList &l)
{
    Lnode *p, *q;
    p = l->next;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    return OK;
}
// get the length of the linklist
int Getlength(LinkList &l)
{
    int length = 0;
    Lnode *p, *q; // p指向当前节点，q指向下一节点
    p = l->next;  // p指向首元节点
    while (p)     //
    {
        q = p->next;
        length++; // 当前节点不为空，则长度+1
        p = q;    // 将当前结点向后移
    }
    return length;
}

bool isEmpty(LinkList &l)
{
    if (l->next == nullptr)
        return true;
    else
        return false;
}

Status getElem(LinkList &l, int i, Item &e)
{
    if (i < 1 || i > Getlength(l))
        return ERROR; // 索引位置为负或者超过链表长度
    Lnode *p;
    p = l->next;
    int id = 1;
    while (p && id < i)
    {
        p = p->next;
        id++;
    }
    if (!p)
        return ERROR else
        {
            e = p->data;
            return OK;
        }
}

Status getIndex(LinkList &l, Item e, int &index)
{
    if (isEmpty(l))
        return ERROR; // 空表

    Lnode *p;
    p = l->next;
    int id = 1;
    while (p && p->data != e)
    {
        p = p->next;
        id++;
    }
    if (!p)
        return ERROR else
        {
            index = id;
            return OK;
        }
}

Status getLocation(LinkList &l, Item e, Lnode *location)
{
    if (isEmpty(l))
        return ERROR;
    Lnode *p;
    p = l->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    if (!p)
        return ERROR else
        {
            location = p;
            return OK;
        }
}

Status Insert(LinkList &l, int i, Item e)
{
    if (i < 1 || i > Getlength(l) + 1)
        return ERROR;
    Lnode *p;
    p = l;
    int id = 0;
    while (p && id < (i-1))
    {
        p = p->next;
        id++;
    }
    if (!p || id > (i - 1))
        return ERROR else
        {
            Lnode *s = new Lnode;
            s->data = e;
            s->next = p->next;
            p->next = s;
            return OK;
        }
}

Status Delete(LinkList &l, int i, Item &e)
{
    if (i < 1 || i > Getlength(l))
        return ERROR;
    Lnode *p;
    p = l;
    int id = 0;
    while (p->next && id < (i-1))
    {
        p = p->next;
        id++;
    }
    if (!(p->next) || id > (i - 1))
        return ERROR else
        {
            Lnode *q = p->next;
            e = q->data;
            p->next = q->next;
            delete q;
            return OK;
        }
}

void headCreate(LinkList &l, int n)
{
    l = new Lnode;
    l->next = nullptr;
    std::cout << "Please Enter " << n << " Elems: "<<std::endl;
    for (int i = n; i > 0; i--)
    {
        std::cout << "Elem#" << i << ": ";
        Lnode *p = new Lnode;
        std::cin >> p->data;
        p->next = l->next;
        l->next = p;
    }
}

void tailCreate(LinkList &l, int n)
{
    l = new Lnode;
    l->next = nullptr;
    Lnode *r = l;
    for (int i = 0; i < n; i++)
    {
        Lnode *p = new Lnode;
        std::cin >> p->data;
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}