- 数据结构是计算机存储、组织数据的方式，指相互之间存在一种或多种特定关系的数据元素的集合
- 算法就是定义良好的计算过程，他取一个或一组的值为输入，并产生出一个或一组值作为输出。（排序、查找、去重）

# Lesson2 算法的时间复杂度和空间复杂度
为什么不再特别关注空间复杂度了？ 摩尔定律

算法的时间复杂度是一个函数。算法中的基本操作的**执行次数**，为算法的时间复杂度。

example:F(N) = N^2+2*N+10 
N = 10 F(N) = 130
N = 100 F(N) = 10210
N = 1000 F(N) = 1002010

计算大概执行次数，采用大O的渐进表示法，O()
- 用常数1取代运行时间中的加法常数
- 在修改后的运行次数函数中，只保留最高阶项
- 如果最高阶项存在且不是1，则去除与这个项目相乘的常数（即系数），得到的结果就是大O阶

常数循环的时间复杂度为O(1)，代表算法运行常数次

# 常用的数据结构
- 数组，字符串
- 链表
- 栈
- 队列
- 双端队列
- 树


# 线性表

## 定义和特点
- 由n（n>=0）个具有相同特性的数据元素的一个有限序列
（a_1, a_2, ..., a_i, a_(i+1), ..., a_n）

*同一线性表中的元素必定具有相同特性，数据元素间的关系是线性关系*
example：学生表、字母表

## 案例
1. 一元多项式的运算：实现两个多项式加、减、乘运算
P_n(x) = p_0+p_1 * x + p_2 * x^2 +...+p_n * x^n

*稀疏多项式* 记录系数和指数
线性表P=((p1,e1), (p2,e2),...,(pn,en))

- 顺序存储结构存在问题
1. 存储空间分配不灵活
2. 运算的空间复杂度高
- 链式存储结构

2. 图书信息管理系统
- 选择合适的存储结构 - 实现此存储结构上的基本操作 - 利用基本操作完成功能

3. 总结
- 线性表中的数据元素可以为简单类型，也可以为复杂类型
- 许多实际应用问题所涉的基本操作有很大的相似性，不应为每个具体应用单独便携一个程序
- 从具体应用抽象出共性的逻辑结构和基本操作（抽象数据类型），然后实现其存储结构的基本操作


## 线性表的类型定义（抽象数据类型）ADT

#define LIST_INIT_SIZE 100;
typedef struct{
    ElemType elem[LIST_INIT_SIZE];
    int length; //用一个变量表示线性表的长度
}SqList;


## 链表
- 链表结构
- 链表的初始化
- 链表的销毁
- 链表的清空
'''
Status ClearList(LinkList &L)
{
    Lnode *p,*q; p节点为要清空的节点，q节点表示下一个节点
    p = L->next;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}
'''
- 求单链表的长度
算法思路：从首元节点开始，依次计数所有节点
‘’‘
int GetLength(LinkList &L)
{
    Lnode *p;
    p = L->next;
    int length = 0;
    while(p)
    {
        length +=1;
        p = p->next;
    }
    return length;
}
’‘’

- 重要操作
p=L; //p指向头节点；
s=L->next; //s指向首元节点
p=p->next; //p指向下一节点

- 取值：取单链表中第i个元素的内容
'''
Status Get(LinkList &L, int i, ElemType& e)
{
    p = L->next; //初始化
    j = 1; 
    // 向后扫描，直到p指向第i个元素或p为空
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p ||j > i) return Error; //第i个元素不存在
    e = p->data; // 取第i个元素
    return OK;
}
'''
- 查找：
    1. 按值查找：根据指定数据获取数据所在位置（地址）
Lnode * Getlocation(LinkList &L, ElemType e)
{
    p = L->next;
    while(p->data != e && p)
    {
        p = p->next;
    }
    return p;
    
}
    2. 按值查找：根据指定数据获取数据所在的位置序号
int GetLoction(LinkList L, ElemType e){
    p = L->next;
    j = 1;
    while (p && p->data != e) {p = p-next; j++}
    if(p) return j;
    else return 0;
}
- 插入：在第i个节点前插入新节点
算法步骤：
    1. 找到第i-1个节点（找到a_(i-1)的存储位置p）
    2. 生成一个数据域为e的新结点s
    3. 插入新结点：1. 新结点的指针域指向a_i 2. 结点a_(i-1)的指针域指向新结点
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
     p = L;
     j = 0;
     while(p && j< i-1 ){p = p->next; j++};
     if(!p ||j>i-1) return ERROR; //i大于表长+1或者小于1，插入位置非法；
     s =new LNode;
     s -> data = e;
     s ->next = p->next;
     p->next = s;
     return OK;

}
- 删除：删除第i的节点
算法步骤:
    1. 找到第i-1个节点的存储位置p，保存要删除的a_i的值
    2. 令p->next的指向指向a_(i+1)
    3. 删除第i个节点；
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    p = L;
    j = 0;
    while (p->next && j < i-1){p = p->next; ++j;}
    if(!(p->next) || j > i-1) return ERROR;
    q = p->next;
    p -> next = q -> next;
    e = q->data;
    delete q;
    return OK;
}
- 单链表的建立
    - 头插法——元素插入在链表头部，也叫前插法
    1. 从一个空表开始，重复读入数据；
    2. 生成一个新结点，将读入数据存在到新结点的数据域中
    3. 从最后一个节点开始，依次将各结点插入到链表的前端
'''
void CreateList_H(LinkList &L, int n)
{
    L = new LNode;
    L-next = Null;
    for(int i = n; i>0; --i)
    {
        p = new LNode;
        cin >> p->data;
        p ->next = L->next;//插入到表头;
        L->next = p;
    }
}
'''
- 尾插法
'''
void CreateList_R(LinkList &L, int n)
{
    L = new LNode;
    L ->next = Null;
    r = L;
    for(int i = 0; i < n; ++i)
    {
        p =new LNode;
        cin >> p->data;
        p ->next =NUll;
        r->next = p;
    }
}
'''

- 循环链表
表的操作常常是在表的首尾位置上进行的
- 循环链表的合并：带尾指针循环链表的合并
LinkList Connect(LinkList Ta, LinkList Tb)
{
    p = Ta->next; //p存表头节点
    Ta ->next = Tb->next->next; //Tb表头连结Ta结尾
    delete Tb->next; // 释放Tb表头节点
    Tb ->next = b; //修改指针
}

- 双向链表

# 栈和队列
## 栈与递归
- 递归的定义：若一个对象部分地包含它自己，或用它自己给自己定义，则称这个对象是递归的；
- 若一个过程直接地或间接地调用自己，则称这个过程是递归的过程；

以下三种情况常常用到递归方法
- 递归定义的数学函数
- 具有递归特性的数据结构（二叉树、广义表）
- 可递归求解的问题

递归问题-用分治法求解
- 分治法：对于一个较为复杂的问题，能够分解成几个相对简单的且解法相同或类似的字问题求解
- 必备的三个条件
1. 能将一个问题转变为一个新问题，而新问题与原问题的解法相同或类同，不同的仅是处理的对象，且这些对象是变化有规律的
2. 可以通过上述转化而使问题简化
3. 必须有一个明确的递归出口，或称递归的边界
- 一般形式
'''
void p(argumentList){
    if (递归结束条件) 可直接求解步骤； --基本项
    else p(较小的参数)； --归纳项
}
'''
