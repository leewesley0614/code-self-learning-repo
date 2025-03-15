# 线性表的查找
1. 顺序查找
- 应用范围
  - 顺序表或线形链表表示的静态查找表
  - 表内元素之间无序
```
typedef struct{
  KeyType key; // 关键字域
  ...
} ElemType; // 数据元素类型定义
typedef struct{
  ElemType *R; // 表基址
  int length; //表长
} SSTable; // Sequential Search Table
SSTable ST; //定义顺序表

int Search_Seq(SSTable ST, KeyType key){
for ( i = ST.length; i>=1; --i)
  if(ST.R[i].key == key) return i;
return 0;

// 改进：增加监视哨
int Search_Seq(SSTable ST, KeyType key){
  ST.R[0].key = key;
  for( i = ST.length; ST.R[i].key!=key; --i); // 空循环
  return i;
}
```
- 优点：算法简单，逻辑次序无要求，且不同存储结构均适用
- 缺点：ASL太长，时间效率太低
2. 二分查找
- 每次将待查记录所在区间缩小一半
  1. 设表长为n，low、high和mid分别指向待查元素所在区间的上界、下界和终点，key为给定的要查找的值
  2. 初始时，令low=1，high=n，mid=「（low+mid)/2」
  3. 让k与mid指向的记录比较
     - 若key==R[mid].key,查找成功
     - 若key<R[mid].key,则high = mid-1
     - 若key>R[mid].key,则low = mid+1
```
// 非递归算法
int Search_Bin(SSTable T, KeyType key){
  low = 1;
  high = ST.length;
  while(low < high){
    mid = (low + high) / 2;
    if(ST.R[mid].key == key) return mid;
    else if(key < ST.R[mid].key) high = mid - 1;
      else low = mid + 1;
  }
  return 0;
}
// 递归算法
int Search_Bin(SSTable T, KeyType key, int low, int high)
{
  if (low > high) return 0;
  mid = (low + high) / 2;
  if(ST.R[mid].key == key) return mid;
  else if(key < ST.R[mid].key) Search_Bin(ST, key, low, mid - 1);
    else Search_Bin(ST, key, mid + 1, high);
}
```
- 优点：效率比顺序查找高
- 缺点：只适用有序表，且限于顺序存储结构（对线形链表无效）
3. 分块查找
条件
- 表分为几块，且表或者有需，或者分块有序
  **若i<j，则第j块中所有记录的关键字均大于第i块中的最大关键字**
- 建立"索引表"（每个结点含有最大关键字域和指向本块的第一个结点的指针，且关键字有序）
查找过程：先确定待查记录所在块（顺序或折半查找），再在块哪查找（顺序查找）
# 树表的查找
- 当表插入、删除操作频繁时，为维护表的有序性，需要移动表中的很多记录**（改用动态查找表——几种特殊的树）**
- 表结构**在查找过程中动态生成**
  对于给定值key，若表中存在，则成功返回；否则，插入关键字等于key的记录
1. 二叉排序树
   二叉排序树（Binary Sort Tree)称为二叉搜索树，二叉查找树
   二叉排序树或是空树，或事满足如下性质的二叉树：
   - 若其左子树非空，则左子树上所有节点的值均小于根结点的值
   - 若其右子树非空，则右子树上所有节点的值均大于等于该节点的值
   - 其左右子树本身又各是一棵二叉排序树
**中序遍历非空的二叉排序树所得到的数据元素序列是一个按关键字排列的递增有序序列**
```
typedef struct{
  KeyType key; // 关键字项
  InfoType otherinfo; // 其他数据域
} ElemType;
typedef struct BSTNode{
  ElemType data; // 数据域
  BSTNode *lchild, *rchild; // 左右孩子指针
}BSTNode, *BSTree;

BSTree T;
```
- 二叉排序树的操作——查找
  1. 若查找的关键字等于根结点，成功
  2. 否则
   - 若小于根结点，查其左子树
   - 若大于根结点，查其右子树
  3. 递归左右子树
算法思想
  1. 若二叉排序树为空，则查找失败，返回空指针
  2. 若二叉排序树非空，将给定值key与根结点的关键字T->data.key比较
     - 若key == T->data.key, 则查找成功，返回根结点地址;
     - 若key < T->data.key, 则进一步查找左子树
     - 若key > T->data.key, 则进一步查找右子树
```
BSTree SearchBST(BSTree T, KeyType key){
  if(!T || key == T->data.key) return T;
  else if (key < T->data.key) return SearchBST(T->lchild, key);
    else return SearchBST(T->rchild, key);
}
```
- 二叉排序树的操作——插入
若二叉排序树为空，则插入节点作为根结点插入到空树中
否则，继续在其左、右孩子树上查找
  - 树中已有，不在插入
  - 树中没有，查找直至某个叶子的左子树或右子树为空位置，则插入节点应为该叶子节点的左孩子或右孩子
- 二叉排序树的操作——生成
一个无序序列可通过构造二叉排序树而变成一个有序序列，构造树的过程就是对无序序列进行排序的过程
- 二叉排序树的操作——删除
从二叉排序树中删除一个节点，不能把以该节点为根的子树都删去，只能删掉该节点，并且还应保证删除后所得到的二叉树仍然满足二叉排序树的性质不变
由于中序遍历二叉排序树可以得到一个递增有序的序列，那么，在二叉排序树中删去一个结点相当于删去有序序列中的一个结点
- 将因删除结点而断开的二叉链表重新链接起来
- 防止重新链接后树的高度增加
2. 平衡排序树
  
3. 红黑树
4. B-树
5. B+树
6. 键树
# 哈希表的查找
基本思想：记录的存储位置与关键字之间存在对应关系
  - 对应关系——hash函数：Loc(i) = H(keyi)
- 散列方法（杂凑法）
- 散列函数：散列方法中使用的转换函数
- 散列表：按上述思想构造的表
- 冲突：不同的关键码映射到同一个散列地址
- 同义词：具有相同函数值的多个关键字
## 散列函数的构造方法
**使用散列表要解决的问题：**
  - 所选函数尽可能简单，以提高转换速度
  - 所选函数对关键码计算出的地址，应在散列地址集中致均匀分布，以减少空间浪费
  - 解决冲突的方案

**构造散列函数考虑的因素**
  - 执行速度
  - 关键字的长度
  - 散列表的大小
  - 关键字的分布情况
  - 查找频率

**根据元素集合的特性构造**
  - n个数据原仅占用n个地址，虽然散列查找是以空间换时间，但仍希望散列的地址空间尽量小
  - 无论用什么方法存储，目的都是尽量均匀地存放元素，以避免冲突

  直接定址法/数字分析法/平方取中法/折叠法/除留余数法/随机数法
1. 开放定址法
   - 基本思想：有冲突时就去寻找下一个空的散列地址，只要散列表足够大，空的散列地址总能找到，并将数据元素存入。

   $`H_{i} = (Hash(key)+d_{i}) mod m`, d_{i}为增量序列`$
   
   常用方法：
   - 线性探测法 d_i为1,2,...,m-1为线性序列
   - 二次探测法 d_i为1^2, -1^2, 2^2, -2^2,...,q^2二次序列
   - 随机探测法 d_i为伪随机数
2. 链地址法
   - 基本思想：相同散列地址的记录链成一个单链表；m个散列地址就设m个单链表，然后用一个数组将m个单链表的表头指针存储起来，形成一个动态结构
