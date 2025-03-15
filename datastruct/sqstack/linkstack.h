typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    StackNode *next;
} StackNode, *LinkStack;

// 链栈的初始化
void InitStack(LinkStack &S)
{
    S = nullptr; // 构造一个空栈，栈顶置针置为空
}
// 判断链栈是否为空
bool StackEmpty(LinkStack &S)
{
    if (S == nullptr)
        return true;
    else
        return false;
}

// 入栈操作
void pull(LinkStack &S, SElemType e)
{
    StackNode *p = new StackNode; // 生成新结点
    p->data = e;                  // 将新结点数据域置为e
    p->next = S;                  // 将新结点插入栈顶
    S = p;                        // 修改栈顶指针；
}
// 出栈操作
bool pop(LinkStack &S, SElemType &e)
{
    if(S  == nullptr) return false;
    e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
    return true;
}

// 获取栈顶元素
void getTop(LinkStack &S, SElemType &e)
{
    if (S!=nullptr)
    {
        e = S->data;
    }
}
