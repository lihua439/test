#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

// 哈夫曼树节点
struct HuffmanNode {
    int lchild, rchild, parent;
    int weight;

    HuffmanNode(int w = 0) {
        lchild = rchild = parent = 0;
        weight = w;
    }
};

typedef HuffmanNode* HuffmanTree;
typedef char** HuffmanCode;

// 选取两个权值最小的节点
void SelectMin(HuffmanTree HT, int top, int &x, int &y) {
    int min1 = INT_MAX, min2 = INT_MAX;
    x = y = 0;

    for (int i = 1; i <= top; ++i) {
        if (HT[i].parent == 0) {
            if (HT[i].weight < min1) {
                y = x; min2 = min1;
                x = i; min1 = HT[i].weight;
            } else if (HT[i].weight < min2) {
                y = i; min2 = HT[i].weight;
            }
        }
    }
}

// 哈夫曼树构建 + 编码
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int w[], int n) {
    if (n <= 1) return;

    int m = 2 * n - 1;
    HT = new HuffmanNode[m + 1];

    // 初始化叶子节点
    for (int i = 1; i <= n; ++i)
        HT[i] = HuffmanNode(w[i - 1]);

    // 构建树
    for (int i = n + 1; i <= m; ++i) {
        int x, y;
        SelectMin(HT, i - 1, x, y);

        HT[x].parent = i;
        HT[y].parent = i;
        HT[i].lchild = x;
        HT[i].rchild = y;
        HT[i].weight = HT[x].weight + HT[y].weight;
    }

    // 生成编码
    HC = new char*[n + 1];
    char* tmp = new char[n];
    tmp[n - 1] = '\0';

    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        int cur = i, p = HT[cur].parent;

        while (p != 0) {
            tmp[--start] = (HT[p].lchild == cur) ? '0' : '1';
            cur = p;
            p = HT[p].parent;
        }

        HC[i] = new char[n - start];
        strcpy(HC[i], &tmp[start]);
    }
    delete[] tmp;
}

// ================== 测试 ==================
int main() {
    int n = 4;
    int weight[] = {7, 5, 2, 4};    // 权重
    char ch[] = {'A', 'B', 'C', 'D'};// 字符

    HuffmanTree HT;
    HuffmanCode HC;

    HuffmanCoding(HT, HC, weight, n);

    cout << "哈夫曼编码：" << endl;
    for (int i = 1; i <= n; ++i)
        cout << ch[i-1] << " : " << HC[i] << endl;

    return 0;
}
