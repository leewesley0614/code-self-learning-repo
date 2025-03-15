# 树
## 基本术语
- 根节点：非空树中无前驱节点的节点
- 节点的度：节点拥有的子树数
- 树的度：树中各节点的度的最大值
- 终端节点（叶子）：度为0的节点
- 分支节点（非终端节点）：度不为0的节点
- 内部节点：根节点以外的分支节点
- 节点的子树的根称作该节点的孩子，该节点成为孩子的双亲；有共同双亲的节点称作兄弟节点
- 祖先：从根到该节点所经分支上的所有节点
- 子孙：以某节点为根的子树的任意节点
- 深度（高度）：树中节点的最大层次
- 有序树：树中节点的各子树从左至右有次序（最左边的为第一个孩子）
- 无序树：树中的各子树无次序
- 森林：是m（m>=0）颗互不相交的树的集合；把根节点删除树就变成了森林；一棵树可以看作成一个特殊的森林；
给森林中的各子树加上一个双亲节点就变成了一棵树

# 二叉树
- 结构简单，规律性强；
- 所有树都能转为唯一对应的二叉树，不失一般性
## 特点
- 每个结点最多有两个孩子
- 子树有左右之分，其次序不能颠倒
- 二叉树可以是空集合，根可以有空的左子树或空的右子树
**二叉树不是树的特殊情况，它们是两个概念**
**二叉树结点的子树要区分左子树和右子树；树当节点只有一个孩子是，就无须区分它是左还是右的次序**
**重要操作：前序遍历；中序遍历；后序遍历；创建二叉树**

## 性质
1. 在二叉树的第i层上至多有2^(i-1)个节点（i >= 1）;第i层至少有1个节点，否则没有该层
2. 深度为k的二叉树至多有2^k - 1个节点; 深度为k的二叉树至少有k个节点
3. 对任何一棵二叉树T，如果其叶子树为n_0,度为2的节点树为n_2，则n_0 = n_2 + 1;

# 满二叉树和完全二叉树（顺序存储下可以复原）
- 满二叉树
  一棵深度为k且有2^k-1个节点的二叉树称为满二叉树
  **每一层上的结点数都是最大节点数**
  **叶子节点全部在最底层**
- 完全二叉树
  深度为k的具有n个节点的二叉树，当且仅当其每一个结点都与深度为k的满二叉树中编号为1～n的结点一一对应
时，称之为完全二叉树
  **在满二叉树中，从最后一个结点开始，连续去掉任意个结点，即结点是一棵完全二叉树**
  **叶子只可能分布在层次最大的两层上**
  **对任意节点，如果其右子树的最大层次为i，则其左子树的最大层次必为i或i+1**
## 性质
1. 具有n个节点的完全二叉树深度为「log_2{n}」+1
2. 如果对一棵有n个节点的完全二叉树，则对任意节点i（1<=i<=n）有
  - 如果i=1，则节点i时二叉树的根，无双亲；如果i>1，则其双亲是节点「i/2」
  - 如果2i>n，则节点i为叶子节点，无左孩子；否则，其左孩子是节点2i；
  - 如果2i+1>n，则节点i无右孩子；否则，其右孩子是节点2i+1
**该性质表明了完全二叉树中双亲节点编号与孩子编号的关系**

# 二叉树的存储结构
## 顺序存储：按满二叉树的节点层次编号，依次存放二叉树中的数据元素
适用于存满二叉树和完全二叉树
```
#define MAXTSIZE 100
Typedef TElemType SqBiTree[MAXTSIZE]
SqBiTree bt;
```
## 链式存储
- 二叉链树
```
typedef struct BiNode{
TElemType data;
BiNode *lchild, *rchild;
}BiNode, *BiTree;
```
- 三叉链树，增加一个双亲节点
```
typedef struct TriTNode{
TElemType data;
TriTNode *lchild,*rchild,*parent;
}TriTnode, *TriTree;
```
# 二叉树的遍历
- 遍历定义：依次访问节点信息
- 遍历方式：先序（根）遍历、中序（根）遍历、后序（根）遍历
- DLR遍历
  - 算法思路：1.遍历根节点；2.遍历左子树；3.遍历右子树（递归思路）三种遍历方式的时间复杂度和空间复杂度都为O(n)
```
Status PreOrderTraverse(BiTree &T)
{
  if(node == null) return -1;
  visit(T); //遍历当前节点
  PreOrderTraverse(node->lchild); //遍历左子树
  PreOrderTraverse(node->rchild); //遍历右子树
}
```
- 中序非递归遍历算法（栈）
  - 基本思想：1. 建立一个栈；2.根节点进栈，遍历左子树；3.根节点出栈，输出根节点，遍历右子树
```
Status InOrderTraverse(BiTree T)
{
  BiTree p;
  InitStack(S);
  p = T;
  while(p || !StackEmpty(S)){
  if(p) {Push(S, p); p = p->lchild;}
  else {Pop(S, q); printf("%c", q->data); p = q->rchild;}
  }
  return OK;
}
```
- 二叉树的层次遍历
  对于一颗二叉树，从根节点开始，按从上到下、从左到右的顺序访问每一个节点；每个节点仅仅访问一次
  - 算法设计思路：使用一个队列
  1. 将根节点入队
  2. 队不空时循环：从队列中出列一个系欸但*p，访问它；
     - 若它有左孩子结点，将左孩子节点进队；
     - 若他有右孩子节点，将右孩子节点进队；
```
typedef struct{
 BTNode data[MaxSize]; //存放队中元素
 int front, rear; //对头和对尾指针
} SqQueue; //顺序循环队列类型
void LevelOrder(BTNode *b)
{
  BTNode *p;
  SqQueue *qu;
  InitQueue(qu); //c初始化列队
  enQueue(qu, b); //根节点指针进入队列
  while(!QueueEmpty(qu)){ //队不为空，循环
    deQueue(qu, p); //出队节点p
    printf("%c", p->data); //访问节点p
    if(p->lchild!=NULL) enQueue(qu, p->lchild); //有左孩子时将其进队
    if(p->rchild!=NULL) enQueue(qu, p->rchild); //有右孩子是将其进队
  }
}
```
- 遍历应用：建立二叉树
```
Status CreateBiTree(BiTree &T)
{
  scanf(&ch); //cin >> ch;
  if(ch == "#") T = NULL;
  else{
    if(!(T=BiTNode*) molloc(sizeof(BiTNode))) exit(OVERFLOW);
  T -> data = ch; //生成根节点
  CreateBiTree(T->lchild); //构造左子树
  CreateBiTree(T->rchild); //构建右子树
  }
  return OK;
}
```
- 遍历应用：赋值二叉树
```
int Copy(BiTree T, BiTree &NewT)
{
  if(T == Null) {NewT = Null; return 0;}
  else{
    NewT = new BiTNode;
    NewT->data = T->data;
    Copy(T->lchild, NewT->lchild);
    Copy(T->rchild, NewT->rchild);
    }
}
```
- 遍历应用：计算二叉树深度
  算法思路：
  - 如果是空树，则深度为0；
  - 否则，递归计算所字数的深度记为m，递归计算右子树的深度记为n，二叉树的深度则为m与n的较大者加1
```
int Depth(BiTree T)
{
  if(T == null) return 0;
  else{
    m = Depth(T->lchild);
    n = Depth(T->rchild);
    if(m > n) return (m+1);
    else return (n+1);
  }
}
```
- 遍历应用： 计算二叉树节点总数
  算法思路：
  - 如果是空树，则节点个数为0；
  - 否则，节点个数为左子树的节点个数+右子树的节点个数+1；
```
int NodeCount(BiTree T)
{
  if(T == null) return 0;
  else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
```
- 遍历应用：计算二叉树叶子节点树（补充）
```
int LeafCount(BiTree T)
{
  if(T==null) return 0;
  if(T->lchild == null && T->rchild == null) return 1;
  else return LeafCount(T->lchild) + LeafCount(T->rchild);
}
}
```
# 线索二叉树
- 使用二叉链表时无法直接找到某结点的前驱结点和后继结点
解决方法
- 通过遍历寻找-费时间
- 再增设前驱、后继指针域——增加存储负担
- **利用二叉链表中的空指针域**
  - 如果某个结点的左孩子为空，则将空的左孩子指针域改为指向前驱；如果某节点的右孩子为空，则将空的右孩子指针与改为指向其后继——这种改变指向的指针称为“线索”
  - 加上了线索的二叉树成为线索二叉树（Threaded Binary Tree）
```
typedef struct BiThrNode{
int data;
int ltag, rtag; //标志域，为1指向前驱或后继，为0指向孩子
BiThrNode *lchild,*rchild;
}BiThrNode, *BiThrTree;
```
**为避免空指针，增设一个头节点**
- ltag=0，lchild指向根节点
- rtag=1，rchild指向遍历序列中最后一个结点
- 办理序列中的第一个节点的lc域和最后一个结点的rc域都指向头节点

# 树和森林
- 双亲表示法
  - 定义结构数组，存放树的结点，每个结点含两个域：
    数据域：存放信息
    双亲域：指示本结点的双亲结点在数组中的位置
- 孩子链表
  把每个结点的孩子结点排列起来，看成是线性表，用单列表存储，则n个节点有n个孩子链表（叶子的孩子链表为空表），而n个头指针又组成一个线性表，用顺序表存储
```
// 孩子节点结构
typedef struct CTNode{
int child;
CTNode *next;
}*ChildPtr;
// 双亲结点结构
typedef struct{
TElemType data;
ChildPtr firstchild;
} CTBox;
// 树结构
typedef struct
{
CTBox nodes[MAX_Tree_SIZE];
int n,r;
}CTree;
```
- 孩子兄弟表示法（二叉树表示法，二叉链表表示法）
  用二叉链表作为树的存储结构，链表中的每个结点的两个指针与分别指向其**第一个孩子结点**和**下一个兄弟结点**
```
typedef struct CSNode{
ElemType data;
CSNode *firstchild, *nextsibling;
}CSNode, *CSTree
```

# 树与二叉树的转换
- 将树转换为二叉树进行处理，利用二叉树的算法来实现对树的操作
- 由于树和二叉树都可以用二叉链表作为存储结构，则以二叉链表做媒介可以导出树和二叉树之间的对应关系
- 给定一个树，可以找到唯一的一颗二叉树与之对应
## 树转换成二叉树
- 加线：兄弟之间加一连线；
- 抹线：对每个结点，除了其左孩子外，去除其与其余孩子之间的关系
- 旋转：以树为根节点为轴心，将整树顺时针转45度
**兄弟相连留长子**
## 二叉树转换成树
- 加线：若p结点是双亲结点的左孩子，则将p的右孩子，右孩子的右孩子......沿分支找到所有的右孩子，斗鱼p的双亲用线连起来
- 抹线：抹掉原二叉树中双亲与右孩子之间的连线
- 调整：将节点按层次排列，形成树结构
# 森林与二叉树的转换
## 森林转换成二叉树
- 将各棵树分别转换成二叉树
- 将每棵树的根节点用线相连
- 以第一颗树根节点为二叉树的根，再以根节点为轴心，顺时针旋转，构成二叉树型结构
## 二叉树转换成森林
- 抹线：将二叉树根节点与其右孩子连线，及沿右分支搜索到的所有右孩子间连线全部抹掉，使之变成孤立的二叉树
- 还原：将孤立的二叉树还原成树

# 树的遍历（三种方式）
- 先根（次序）遍历：若树不空，则先访问根节点，然后依次先根遍历各棵子树
- 后根（次序）遍历：若树不空，则先依次后跟遍历各棵子树，然后访问根节点
- 按层次遍历：若树不空，则自上而下自左至右访问树中各个结点
# 森林的遍历
将森林看作由三部分组成
1. 森林中第一颗树的根节点；
2. 森林中第一棵树的子树森林；
3. 森林中其他树构成的森林；
- 中序遍历
若森林不空，则
1. 中序遍历森林中第一棵树的子树森林
2. 访问森林中第一棵树的根节点
3. 中序遍历森林中（除第一棵树外）其余树构成的森林
