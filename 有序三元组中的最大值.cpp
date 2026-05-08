2874. 有序三元组中的最大值 II
给你一个下标从 0 开始的整数数组 nums 。

请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0 。

下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 
已知：
1整数数组nums
2 下标三元组定义
3 值都是负数，返回0
4 求下标三元组的最大值
隐藏：
1. 三元组的问题可以用枚举中间和枚举第三个元素的做法
2. 三元组的值可能都是负数
3. 数组的顺序不能变，i < j < k
4. 在i<j 的情况下，求nums[i] - nums[j]的最大值可以用枚举右边的做法
突破口：
枚举第三个下标-> 用枚举右边，变量左边的方法求出第三个下标左边nums[j]-nums[i]的最大值
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long preMax = nums[0];
        long long Max = nums[0] - nums[1];
        int j = 1;
        for(int i = 2; i < nums.size(); i++)
        {
            ans = max(ans,nums[i] * Max);
            if(nums[j] > preMax) preMax = nums[j];
            j++;
            Max = max(Max,preMax-nums[j]);
            cout<<Max<<" ";
        }
        if(Max < 0) return 0;
        return ans;
