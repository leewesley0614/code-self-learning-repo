
typedef struct student
{
    char num[8];  // 数据域
    char name[8]; // 数据域
    int score;    // 数据域
    struct student *next;
} Lnode, *LinkList;

LinkList L;

// 统一定义
typedef struct
{
    char num[8];
    char name[8];
    int score;
} ElemType;

typedef struct Lnode
{
    ElemType data;
    Lnode *next;
} Lnode, *LinkList;

void InniLinkList(LinkList &L)
{
    L = new Lnode;     // 生成新节点作为头节点，用头指针L指向头节点
    L->next = nullptr; // 将头节点的指针域置空
}

bool isEmpty(LinkList &L)
{
    if(L->next) return 0; //判断头节点的指针域是否为空
    else return 1;
}

