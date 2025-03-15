#include "sqstack.h"

bool InitSqStack(SqStack &S)
{
    S.base = new SQElemType[MAXSIZE]; // 分配栈空间
    S.top = S.base;                   // 栈底等于栈顶
    S.sqstacklength = MAXSIZE;        // 栈空间最大长度为MAXSIZE
}

bool StackEmpty(SqStack &S)
{
    if (S.top == S.base) // 栈底指针等于栈顶指针相等时栈为空
        return true;
    else
        return false;
}

int getLength(SqStack &S)
{
    return (S.top - S.base);
}

bool ClearStack(SqStack &S)
{
    if (S.base)
        S.top = S.base;
    return true;
}

bool DestroyStack(SqStack &S)
{
    if (S.base)
    {
        delete S.base; // 释放栈空间
        S.sqstacklength = 0;
        S.base = S.top = nullptr;
    }
    return true;
}

bool pull(SqStack &S, SQElemType e)
{
    if (S.top - S.base == S.sqstacklength)
        return false; // 判断是否栈满，若满则出错（溢出）
    *(S.top) = e;     // 元素e压入栈顶
    (S.top)++;        // 栈顶指针+1
    return true;
}

bool pop(SqStack &S, SQElemType &e)
{
    if (S.top == S.base)
        return false; // 判断是否栈空，若空则溢出
    e = *(S.top--); // 获取栈顶元素e, 并将栈顶指针减-1
    return true;
}