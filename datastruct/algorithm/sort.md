# 插入排序
基本思想：每步将一个待排序的对象，按其关键码大小，插入到前面已经排好序的一组对象的适当位置上，直到对象全部插入为止
**边插入边排序**
- 基本操作：有序插入
  - 在有序序列中插入一个元素，保持序列有序，有序长度不断增加
  - 起初，a[0]时长度为1的子序列，然后，逐一将a[1]至a[n-1]插入到有序子序列中
- 顺序法定位插入位置——直接插入排序
```
void InsertSort(SqList &L){
  int i, j;
  for(i = 2; i<=L.length; ++i){
  if (L.r[i].key < L.r[i-1].jey{ //若"<",需将L.r[i]插入有序子表
    L.r[0] = L.r[i] // 复制为哨兵
    for(j = i - 1; L.r[0].key < L.r[j].key; --j){
      L.r[j+1] = L.r[j]; // 记录后移
    }
    L.r[j+1] = L.r[0]; //插入到正确位置
  }
} 
```
- 二分法定位插入位置——二分插入排序
```
void BInsertSort(SqList &L)
{
  for (i = 2; i <= L.length; ++i){
    L.r[0] = L.r[i] // 复制为哨兵
    low = 1; high = i - 1; // 采用二分查找
    while(low <= high){
    mid = (low + high) / 2;
    if(L.r[0].key < L.r[mid].key) high = mid - 1;
    else low = mid + 1;
    } //循环结束, high + 1为插入位置
    for (j = i - 1; j>=high + 1; --j) L.r[j+1] = L.r[j]; //移动元素
    L.r[high+1] = L.r[0]; //插入到正确位置
    }
}
```
- 缩小增量多变插入排序——希尔排序
  - 基本思想：先将整个代排记录序列分割成若干子序列，分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行一次直接插入排序
  - 思路
  1. 定义增量序列$`D_{k}:D_{M} > D_{M-1} >...>D_{1}=1`$
  2. 对每个$`D_{k}`$-间隔插入排序
```
void ShellInsert(SqList &L, int dk){
  for(i = dk+1; i < L.length; ++i){
  r[0] = r[i];
  for(j = i-dk; j>0&&(r[0].key < r[j].key); j = j - dk)
    r[j+dk] = r[j];
  r[j+dk] = r[0];
  }
}
void ShellSort(Sqlist& L, int dlta[], int t{
  for(k = 0; k < t; ++k)
    ShellInsert(L, dlta[k]); // 一趟增量为dlta[k]的插入排序
}
```

# 交换排序
基本思想： 两两比较，如果发生逆序则交换，直到所有记录都排好序为止
## 冒泡排序
  - 基本思想：每趟不断将记录两两比较，并将前小后大规则交换
```
void bubble_sort(SqList &L){
  int m, i, j;
  RedType x;
  for(m = 1; m <= n-1; m++) { // 总共需m躺
    for(j = 1; j <= n-m; j++)
      if(L.r[j].key > L.r[j+1].key){ // 发生n序
        x = L.r[j];
        L.r[j] = L.r[j+1];
        L.r[j+1] = x;
      }
  }  
}
// 改进的冒泡排序
void bubble_sort(Sqlist &L){
  int m, i, j, flag = 1; //flag作为是否有交换的标记
  RedType x;
  for(m = 1; m <= n-1&&flag == 1; m++{
  flag = 0;
  for(j = 1; j < =m; j++)
    if(L.r[j].key > L.r[j+1].key){
      flag = 1; //发生交换，flag置为1，若本趟没发生交换，flag保持为0
      x = L.r[j]; L.r[j] = L.r[j+1]; L.r[j+1] = x;
      }
  } 
}
```
## 快速排序
**改进的交换排序**
- 基本思想
  - 任取一个元素（如第一个）为中心
  - 所有比他小的元素一律前放，比它大的元素一律后放，形成左右两个子表
  - 对各子表重新选择中心元素并依次规则调整
  - 直至每个子表的元素只剩一个
```
void QSort(SqList &L, int low, int high){
  if(low < high){// 长度大于1
    pivotloc = Partition(L, low, high); // 将L.r[low..high]一分为二，pivotloc为枢纽元素排序序的位置
    QSort(L, low, pivotloc-1);// 对低子表递归排序
    QSort(L, pivotloc+1, high); // 对高子表递归排序
}
int Partition(SqList& L, int low, int high){
  while(low<high){
    while(low < high && L.r[high].key>=pivotkey) --high;
    L.r[low] = L.r[high];
    while(low > high && L.r[low].key <= pivotkey) ++ low;
    L.r[high] = L.r[low];
  }
  L.r[low] = L.r[0];
  return low;
```
## 简单选择排序
- 基本思想：在待排序的数据中选出最大（小）的元素放在其最终的位置
```
void SelectSort(SqList &K)
{
  for(i = 1; i<length; ++i){
    k = i;
    for(j = i+1; j < L.length; j++)
      if(L.r[j].key < L.r[k].key) k = j; //记录最小值位置
    if(k != i) swap(L.r[i], L.r[k]); //交换
}
```
## 堆排序
- 若n个元素的序列$`{a_1, a_2, ..., a_n}`$满足$`a_i <= a_{2i}, a_i <= a_{2i+1}`$（或>=)，则分别称该序列`{a_1, a_2, ..., a_n)`$为小根堆或大根堆
- 从堆的定义可以翻出，堆实质是满足如下性质的完全二叉树，二叉树中任意非叶子节点均小于(大于）它的孩子结点
- 若在输出堆顶的最小值（最大值）后，使得剩余n-1元素的序列充又建成一个堆，则得到n个元素的次小值（次大值），如此反复，便能得到一个有序序列，这个过程称之为堆排序
- 问题：
  1. 如何有一个无序序列建成一个堆
  2. 如何在输出堆顶元素后，调整剩余元素为一个新的堆
- 以小根堆为例
  1. 输出堆顶元素之后，以堆中最后一个元素替代之
  2. 然后将根结点值与左、右子树的根结点值进行比较，并与其中小者进行交换
  3. 重复上述操作，直至叶子节点，将得到新的堆，称这个从堆顶至叶子的调整过程为“筛选”
```
void HeapAdjust(elem R[], int s, int m)
{
  rc = R[s];
  for(j = 2*s; j<=m; j*2){ //沿key较大的孩子结点向下筛选
    if(j < m && R[j]<R[j+1]) ++j; //j为key较大的记录的下标
    if(rc >= R[j]) break;
    R[s] = R[j];
    s = j; // rc应插入在位置s上
  }//for
  R[s] = rc; 插入
}
```
- 建立堆
  1. 单节点的二叉树是堆
  2. 在完全二叉树中所有以叶子节点(序号i>n/2)为根的子树是堆
  3. 这样，我们只需依次以序号为n/2,n/2-1,...1的节点为根的子树均调整为堆即可
```
for(i=n/2; i>=1; i--) HeapAdjust(R, i, n);
```
- 堆排序
```
void HeapSort(elem R[]){
  int i;
  for(i = n/2; i>=1; i--) HeapAdjust(R, i, n); // 建立初堆
  for(i = n; i>1; i--){
    Swap(R[1], R[i]) //根与最后一个元素交换
    HeapAdjust(R, 1, i-1); // 对R[1]到R[i-1]重新建堆
  }
}
```
## 归并排序
- 基本思想：将两个或两个以上的有序子序列"归并"为一个有序序列
- 在内部排序中，通常采用的是2-路归并排序。即：将两个位置相邻的有序子序列R[l..m]和R[m+1..n]归并为一个有序序列R[l..n]
- 

