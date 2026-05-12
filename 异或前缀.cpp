原理：a^0 = a a^a = 0   异或：相同为0，相异为1
(a^b)^(a^b^c) = a^a^b^b^c=c
对于异或前缀数组s来说，s[i]^s[j] = ai^ai+1^...^aj
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>s(n+1,0);
        for(int i = 1; i < n+1; i++)
        {
            s[i] = s[i-1]^arr[i-1];
        }
        vector<int>ans;
        for(auto &it : queries)
        {
            ans.push_back(s[it[1]+1]^s[it[0]]);
        }
        return ans;
    }
};
