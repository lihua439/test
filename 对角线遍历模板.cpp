给你一个下标从 0 开始、大小为 m x n 的二维矩阵 grid ，请你求解大小同样为 m x n 的答案矩阵 answer 。

矩阵 answer 中每个单元格 (r, c) 的值可以按下述方式进行计算：

令 topLeft[r][c] 为矩阵 grid 中单元格 (r, c) 左上角对角线上 不同值 的数量。
令 bottomRight[r][c] 为矩阵 grid 中单元格 (r, c) 右下角对角线上 不同值 的数量。
然后 answer[r][c] = |topLeft[r][c] - bottomRight[r][c]| 。

返回矩阵 answer 。

矩阵对角线 是从最顶行或最左列的某个单元格开始，向右下方向走到矩阵末尾的对角线。

如果单元格 (r1, c1) 和单元格 (r, c) 属于同一条对角线且 r1 < r ，则单元格 (r1, c1) 属于单元格 (r, c) 的左上对角线。类似地，可以定义右下对角线。
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector ans(m, vector<int>(n));
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 计算 top_left[i][j]
                st.clear();
                for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
                    st.insert(grid[x][y]);
                }
                int top_left = st.size();

                // 计算 bottom_right[i][j]
                st.clear();
                for (int x = i + 1, y = j + 1; x < m && y < n; x++, y++) {
                    st.insert(grid[x][y]);
                }
                int bottom_right = st.size();

                ans[i][j] = abs(top_left - bottom_right);
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/solutions/2287367/cong-o503-dao-o502-by-endlesscheng-5wp4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
