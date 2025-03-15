# 数据结构
- 线性结构：一对一
- 树形结构：一对多
- 图形结构：多对多

# 图的定义和基本术语
graph:G=(V,E)
- V:顶点（数据元素）的有穷非空集合
- E:边的有穷集合
**图可以只有结点，没有边**
- 无向图：每条边都是无方向的
- 有向图：每条边都是由方向的
- 完全图：任意两个点都有一条边相连
  - 无向完全图：m=n(n-1)/2（m为边数，n为结点数）
  - 有向完全图：m=n(n-1)
- 稀疏图：有很少的边或弧的图（m<nlog{n})
- 稠密图：有较多边或弧的图
- 网：边/弧带权的图
- 邻接：有边/弧相连的两个顶点之间的关系；即存在$`(v_{i},v_{j})`$,则称$`v_i`$和$`v_j`$互为邻接点（有向图为邻接和邻接于）
- 关联（依附）：边/弧与顶点之间的关系
- 顶点的度：与该顶点相关联的边的树木，记为TD(v)
  - 在有向图中，顶点的度等为该顶点的入度和出度之和
  - 当有向图中仅1个顶点的入度为0，其余顶点的入度均为1，此时图是一棵有向树
- 路径：接续的边构成的顶点序列
- 路径长度：路径上的边或弧的数目/权值之和
- 回路（环）：第一个顶点和最后一个顶点相同的路径
- 简单路径：除路径起点和终点可以相同外，其余顶点均不相同的路径
- 简单回路（简单环）：除路径起点和终点相同外，其余顶点均不相同的路径
- 连通图（强连通图）：在无（有）向图G=(V,{E})中，若对任何两个顶点v，u都存在从v到u的路径，则称G是连通图（强连通图）
- 权与网：图中的边或弧所具有的相关数称为权。表明从一个顶点到另一个顶点的距离或耗费；带权的图称为网
- 子图：设有两个图$`G=(V,{E})`$、$`G_1=(V_1, {E_1})`$，若$`V_1 \in V`$，$`E_1 \in E`$，则称$`G_1`$是$`G`$的子图
- 连通分量（强连通分量）
  - 无向图G的极大连通子图称为G的连通分量
    - 极大连通子图意思是，若子图是G连通子图，将G的任何不在该子图中的顶点加入，子图不再连通
  - 有向图G的极大连通子图称为G的强连通分量
- 极小连通子图：该子图是G的连通子图，若在该子图中删除任何一条边子图不再连通
- 生成树：包含无向图G的所有顶点的极小连通子图
- 生成森林：对非连通图，由各个连通分量的生成树的集合

# 图的类型定义和操作
- CreateGraph(&G, V, VR)
  - 初始条件:V是图的顶点集，VR是图中弧的集合
  - 操作结果:按V和VR的定义构造图
- DFSTraverse(G)
  - 初始条件：图G存在
  - 操作结果：对图进行深度优先遍历
- BFSTraverse(G)
  - 初始条件: 图G存在
  - 操作结果: 对图进行广度优先遍历

- 数组表示法（邻接矩阵）
建立一个顶点表（记录各个顶点信息）和一个邻接矩阵（表示各个顶点之间的关系）
```
#define MVNum 100 //最大顶点数
#define MaxInt 32767 //表示极大值，即∞
typedef char VerTexType; // 设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整型
typedef struct{
  VerTextType vex[MVNum]; //顶点表
  ArcType arc[MVNum][MVNum]; //邻接矩阵
  int vexnum, arcnum; //图的当前点数和边树
}AMGraph // Adjacency Matrix Graph;
```
采用邻接矩阵表示法创建无向网
1. 输入总顶点数和总边数
2. 依次输入点的信息存入顶点表中
3. 初始化邻接矩阵，使每个权值初始化为极大值
4. 构造邻接矩阵
```
Status CreateUDN(AMGraph &G)
{
  cin >> G.vexnum>>G.arcnum; //输入顶点数和节点数
  for(int i = 0; i < G.vexnum; ++i)
  {
    cin >> G.vexs[i]; //依次输入结点信息
  }
  // 初始化邻接矩阵
  for(int i = 0; i < G.vexnum; ++i)
    for(int j = 0; j < G.vexnum; ++j)
    {
      G.arcs[i][j]=MaxInt;
    }
  // 构造邻接矩阵
  for(int k = 0; k < G.arcnum; ++k)
  {
    cin >> v1>>v2>>w; //输入一点边依附的顶点及边的权值
    i = LocateVex(G, v1); 
    j = LocateVex(G, v2); //确定v1和v2在G中的位置
    G.arc[i][j] = w; // 边<v1,v2>的权值置为w
    G.arc[j][i] = G.arcs[i][j]; //置<v1, v2>的对称边<v2, v1>的权值为w
  }
  return OK;
}
```
  - 优点
    1. 直观、简单、好理解
    2. 方便检查任意一堆顶点之间是否存在边
    3. 方便找任意顶点的所有“邻接点”（有边直接相连的顶点）
    4. 方便计算任意顶点的度（从该点发出的边数为“出度”，指向该点的边树为“入度”）
       - 无向图：对应行（或列）非0元素的个数
       - 有向图：对应行非0元素的个数是“出度”，对应列非0元素的个数是“入度”
  - 缺点
    1. 增加和删除结点麻烦
    2. 浪费空间——存稀疏图(点很多但边很少）有大量无效元素
    3. 浪费时间——统计稀疏图中一共有多少条边
- 多重链表
  - 邻接表
    - 无向图的邻接表
  顶点：按编号顺序将顶点数据存储在一维数组
  关联同一顶点的边：用线性链表存储
    - 特点
    1. 邻接表不唯一
    2. 若无向图中有n个顶点、m条边，则其邻接表n个头节点和2e个表结点，适宜存储稀疏图
    3. 无向图中顶点v_i的度为第i个单链表中的节点数
    - 有向图的邻接表：只存储以当前结点为弧尾的弧
    - 特点
    1. 顶点v_i的出度为第i个单链表中的结点个数
    2. 顶点v_i的入读为整个单链表中邻接点域值是i-1的结点个数
    3. 逆邻接表
```
#define MVNum 100 //最大顶点数

typedef struct ArcNode{ //边结点
int adjvex; //该边所指向的顶点的位置
struct ArcNode *nextarc; // 指向下一条边的指针
OtherInfo info; // 和边相关的信息
}ArcNode;

typedef struct VNode{
  VerTexType data; //顶点信息
  ArcNode *firstarc; //指向第一条依附该节点的边的指针
}VNode, AdjList[MVNum]; //AdjList表示邻接表类型

typedef struct{
  AdjList vertices;
  int vexnum, arcnum; //图的当前顶点数和弧数
}ALGraph;
```
算法思想
1. 输入总顶点数和总边数
2. 建立顶点表
   - 依次输入点的信息存入顶点表中
   - 使每个表头结点的指针域初始化为NULL
3. 创建邻接表
   - 依次输入每条边顶点的两个顶点
   - 确定两个顶点的序号i和j，建立边结点
   - 将此边结点分别插入到v_i和v_j对应的两个边链表的头部
```
Status CreateUDG(ALGraph &G)
{
  cin >> G.vexnum >> G.arcnum;
  for(int i = 0; i < G.vexnum; ++i)
  {
    cin >> G.vertices[i].data;
    G.vertices[i].firstarc = NULL;
  }
  for(int k = 0; k < G>arcnum; ++k)
  {
    cin >> v1 >> v2;
    i = LocateVex(G. v1);
    j = LocateVex(G, v2);
    p1 = new ArcNode;
    p1->adjvex = j;
    p1->nextArc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;
    p2 = new ArcNode;
    p2->adjvex = i;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
  }
  return OK'
} 
```
  - 邻接多重表
    - 有向图求解点的度困难——十字链表
    - 无向图每条边都要存储两边——邻接多重表
  - 十字链表
# 图的遍历
图的特点：图中可能存在回路，且图中的任一顶点都可能与其他顶点相同，在访问完某个顶点之后可能会沿着某些边又回到了曾经访问过的顶点
怎么避免重复访问？
- 解决思路：设置辅助数组visited[n]，用来标记每个被访问过的顶点
  - 初始状态visited[i]为0
  - 顶点i被访问，改visited[i]为1，防止被多次访问
常用遍历方法
- DFS（Depth_first search)
```
void DFS(AMGraph G, int v){
  cout << v;
  visit[v] = true;
  for(int w = 0; w < G.vexnum; w++)
    if((G.arcs[v][w]!=0) && (!visited[w])) DFS(G,w); //w是v的邻接点，如果w未访问，则递归调用DFS
}
```
- BFS（Breadth_first search)
```
void BFS(Graph G, int v) // 广度优先搜索
{
  cout << vl； visited[v] = true; 访问第v个结点
  InitQueue(Q); 辅助队列Q初始化，置空
  EnQueue(Q, v); // v进队
  while(!QueueEmpty(Q)) // 队列非空
  {
    DeQueue(Q,u); // 队头元素出队并置为u
    for(w = FirstAdjVex(G, u); w > = 0; w = NextAdjVex(G, u, w))
      if(!visited[w]){ //w为u的尚未访问的邻接顶点
        cout << w; visited[w]=true; EnQueue(Q, w); //w进队
      }
  }
}
}
```

# 最小生成树
给定一个无向网络，在该网的所有生成树中，使得个边权值之和最小的那颗生成树称为该网的最小生成树，也叫最小生成树
MST性质：设$`N=(V,E)`$是一个连通网，U是顶点集V的一个非空子集。若边$`(u,v)`$是一条具有最小权值的边，其中$`u \in {U}, v \in (V-U)`$,则必存在一颗包含边$`(u, v)`$的最小生成树
