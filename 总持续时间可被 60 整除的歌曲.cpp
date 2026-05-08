在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。
已知： 1. 整数数组time
2. 歌曲对定义
3. 求歌曲对的数量
隐藏：
1. 歌曲对的元素不能重复
2. 可以参考两数之和，用哈希表记录target-time[i]
3. 由于是整除， 所以在哈希表里的元素要做取模处理，哈希表的下标范围为0-59，所有在查找哈希表时也要先取模后查找
4. 负数取模还是负数，在这题没有影响，其他题取模后是负数要加上target
5. 枚举方法可以枚举右边遍历左边
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>haxi;
        int ans = 0;
        for(auto &i : time)
        {
            int a = i%60;
            ans+=haxi[a];
            haxi[(60-a)%60]++;
        }
        return ans;
    }
};
