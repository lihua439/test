如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。

你有一个整数数组 nums 和一个二维整数矩阵 queries，对于 queries[i] = [fromi, toi]，请你帮助你检查 子数组 nums[fromi..toi] 是不是一个 特殊数组 。

返回布尔数组 answer，如果 nums[fromi..toi] 是特殊数组，则 answer[i] 为 true ，否则，answer[i] 为 false 。
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> s(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            s[i] = s[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
        }
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto& q = queries[i];
            ans[i] = s[q[0]] == s[q[1]];
        }
        return ans;
    }
};
已知：1.整数数组nums
  2.二维整数矩阵 queries
  3.特殊数组定义
  4.求布尔数组 answer
隐藏：
1.查询类题目多用前缀和数组
2.子数组中有一个不满足nums[i]%2 != nums[i+1]%2就不是特殊数组
3.可以用前缀和数组记录到第i个元素有多少种nums[i]%2 == nums[i+1]%2的情况，如果在查询区间内数量增加，那么该区间不是特殊数组
突破口：子数组中有一个不满足nums[i]%2 != nums[i+1]%2就不是特殊数组-》可以用前缀和数组记录到第i个元素有多少种nums[i]%2 == nums[i+1]%2的情况，如果在查询区间内数量增加，那么该区间不是特殊数组
