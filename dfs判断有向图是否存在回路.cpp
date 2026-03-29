#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int Vertex;
typedef char VertInfo;
typedef struct EdgeNode *Position;

struct EdgeNode {
    Vertex dest;
    Position next;
};

typedef struct HeadNode *AdjList;
struct HeadNode {
    Position adj;
    VertInfo data;
};

typedef struct LGraphNode *LGraph;
struct LGraphNode {
    int n_verts;   // 顶点数
    int m_edges;   // 边数
    AdjList *ver_list;  // 邻接表（你原来写成 Adjlist）
    bool directed;
};

// ====================== 修复 DFS 判环 ======================
bool dfs(LGraph graph, int *visited, int *recstack, int v)
{
    visited[v] = 1;       // 修复：v 不是 i
    recstack[v] = 1;

    // 修复：ver_list 不是 Adjlist
    Position p = graph->ver_list[v]->adj;

    while (p != NULL) {
        int w = p->dest;

        if (!visited[w]) {
            if (dfs(graph, visited, recstack, w) == true) { // == 不是 =
                return true;
            }
        }
        else if (recstack[w]) { // 在当前递归栈 → 有环
            return true;
        }
        p = p->next;
    }

    recstack[v] = 0;  // 回溯
    return false;
}

// ====================== 修复 判断是否为有向无环图 ======================
bool IsAcyclic(LGraph graph)
{
    // 修复：n_verts 不是 n_vert
    int *visited = (int*)calloc(graph->n_verts, sizeof(int));
    int *recstack = (int*)calloc(graph->n_verts, sizeof(int));

    bool has_cycle = false;

    for (int i = 0; i < graph->n_verts; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, recstack, i)) {
                has_cycle = true;
                break;  // 发现环，直接退出
            }
        }
    }

    free(visited);
    free(recstack);

    // 无环图返回 true，有环返回 false
    return !has_cycle;
}
