#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VEX 100  // 最大顶点数

// 邻接表节点结构
typedef struct EdgeNode {
    int adjvex;               // 邻接顶点的索引
    struct EdgeNode *next;    // 指向下一个邻接节点
} EdgeNode;

// 顶点结构
typedef struct VexNode {
    int data;                 // 顶点数据（此处用编号，可扩展为其他类型）
    EdgeNode *firstedge;      // 指向第一个邻接节点
} VexNode;

// 邻接表结构（图）
typedef struct {
    VexNode adjlist[MAX_VEX];  // 顶点数组
    int vexnum, edgenum;      // 顶点数、边数
} AdjGraph;

// 初始化邻接表
void InitGraph(AdjGraph *G) {
    G->vexnum = G->edgenum = 0;
    for (int i = 0; i < MAX_VEX; i++) {
        G->adjlist[i].data = i;  // 顶点编号默认0~n-1
        G->adjlist[i].firstedge = NULL;
    }
}

// 构建邻接表（无向图）
void CreateGraph(AdjGraph *G) {
    printf("请输入顶点数和边数：");
    scanf("%d%d", &G->vexnum, &G->edgenum);

    // 输入边（v1, v2），构建邻接表
    for (int k = 0; k < G->edgenum; k++) {
        int v1, v2;
        printf("请输入边(vi, vj)的顶点编号：");
        scanf("%d%d", &v1, &v2);

        // 检查顶点编号合法性
        if (v1 < 0 || v1 >= G->vexnum || v2 < 0 || v2 >= G->vexnum) {
            printf("顶点编号非法！重新输入\n");
            k--;
            continue;
        }

        // 创建边节点，添加到v1的邻接表
        EdgeNode *p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = v2;
        p->next = G->adjlist[v1].firstedge;
        G->adjlist[v1].firstedge = p;

        // 无向图：添加v2到v1的边
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = v1;
        p->next = G->adjlist[v2].firstedge;
        G->adjlist[v2].firstedge = p;
    }
}

// 访问标记数组
int visited[MAX_VEX];

// 深度优先搜索（递归）
void DFS(AdjGraph *G, int v) {
    printf("%d ", G->adjlist[v].data);  // 访问当前顶点
    visited[v] = 1;                     // 标记已访问

    // 遍历邻接节点
    EdgeNode *p = G->adjlist[v].firstedge;
    while (p != NULL) {
        if (!visited[p->adjvex]) {      // 未访问则递归
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

// 广度优先搜索（队列实现）
void BFS(AdjGraph *G, int start) {
    int queue[MAX_VEX], front = 0, rear = 0;          // 队列
    memset(visited, 0, sizeof(visited));      // 重置访问标记

    printf("%d ", G->adjlist[start].data);    // 访问起始顶点
    visited[start] = 1;
    queue[rear++] = start;                    // 入队

    while (front < rear) {                   // 队列非空
        int v = queue[front++];              // 出队
        EdgeNode *p = G->adjlist[v].firstedge;
        while (p != NULL) {                  // 遍历邻接节点
            if (!visited[p->adjvex]) {
                printf("%d ", G->adjlist[p->adjvex].data);
                visited[p->adjvex] = 1;
                queue[rear++] = p->adjvex;   // 入队
            }
            p = p->next;
        }
    }
}

// 测试邻接表的DFS/BFS
void TestGraphTraversal() {
    AdjGraph G;
    InitGraph(&G);
    CreateGraph(&G);

    // 深度优先遍历
    memset(visited, 0, sizeof(visited));
    printf("\n深度优先遍历结果（从顶点0开始）：");
    DFS(&G, 0);

    // 广度优先遍历
    printf("\n广度优先遍历结果（从顶点0开始）：");
    BFS(&G, 0);
    printf("\n");
}








#define MAX_VEX 100  // 最大顶点数
#define INF INT_MAX  // 表示无边（无穷大）

// 邻接矩阵存储网（带权无向图）
typedef struct {
    int vexnum, edgenum;      // 顶点数、边数
    int adj[MAX_VEX][MAX_VEX];// 邻接矩阵：权值，INF为无边
    int vex[MAX_VEX];         // 顶点数据（编号）
} MGraph;

// 初始化邻接矩阵
void InitMGraph(MGraph *G) {
    G->vexnum = G->edgenum = 0;
    for (int i = 0; i < MAX_VEX; i++) {
        G->vex[i] = i;  // 顶点编号默认0~n-1
        for (int j = 0; j < MAX_VEX; j++) {
            G->adj[i][j] = (i == j) ? 0 : INF;  // 自身权值为0，其余为M
        }
    }
}

// 构建邻接矩阵（无向网）
void CreateMGraph(MGraph *G) {
    printf("请输入网的顶点数和边数：");
    scanf("%d%d", &G->vexnum, &G->edgenum);

    // 输入边（v1, v2, weight），构建邻接矩阵
    for (int k = 0; k < G->edgenum; k++) {
        int v1, v2, w;
        printf("请输入边(vi, vj)的顶点编号和权值：");
        scanf("%d%d%d", &v1, &v2, &w);

        // 检查顶点编号合法性
        if (v1 < 0 || v1 >= G->vexnum || v2 < 0 || v2 >= G->vexnum) {
            printf("顶点编号非法！重新输入\n");
            k--;
            continue;
        }

        // 无向网：双向赋值
        G->adj[v1][v2] = w;
        G->adj[v2][v1] = w;
    }
}

// Prim算法构建最小生成树（从顶点0开始）
void Prim(MGraph *G) {
    int lowcost[MAX_VEX];  // 生成树到各顶点的最小权值
    int vset[MAX_VEX];     // 标记顶点是否在生成树中
    int sum = 0;           // 最小生成树总权值

    // 初始化：从顶点0出发
    for (int i = 0; i < G->vexnum; i++) {
        lowcost[i] = G->adj[0][i];
        vset[i] = 0;
    }
    vset[0] = 1;  // 顶点0加入生成树

    // 依次加入剩余n-1个顶点
    for (int i = 1; i < G->vexnum; i++) {
        //找lowcost中最小的未加入顶点u
        int min = INF, u = -1;
        for (int j = 0; j < G->vexnum; j++) {
            if (vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j];
                u = j;
            }
        }

        if (u == -1) {
            printf("网不连通，无法构建最小生成树！\n");
            return;
        }

        // 输出选中的边（v是生成树中与u相连的顶点）
        int v = -1;
        for (int j = 0; j < G->vexnum; j++) {
            if (vset[j] == 1 && G->adj[j][u] == min) {
                v = j;
                break;
            }
        }
        printf("选中边：(%d, %d)，权值：%d\n", v, u, min);
        sum += min;
        vset[u] = 1;  // 将u加入生成树

        //更新lowcost（生成树到未加入顶点的最小权值）
        for (int j = 0; j < G->vexnum; j++) {
            if (vset[j] == 0 && G->adj[u][j] < lowcost[j]) {
                lowcost[j] = G->adj[u][j];
            }
        }
    }

    printf("最小生成树总权值：%d\n", sum);
}

// 测试Prim算法
void TestPrim() {
    MGraph G;
    InitMGraph(&G);
    CreateMGraph(&G);
    printf("\nPrim算法构建最小生成树过程：\n");
    Prim(&G);
}





int main() {
    // 邻接表 + DFS/BFS
    printf("===== 测试邻接表的DFS和BFS =====\n");
    TestGraphTraversal();

    // 邻接矩阵 + Prim最小生成树
    printf("\n===== 测试邻接矩阵的Prim最小生成树 =====\n");
    TestPrim();

    return 0;
}