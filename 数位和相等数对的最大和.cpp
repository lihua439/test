//342. 数位和相等数对的最大和
给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。
请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值。如果不存在这样的下标对，返回 -1。//
已知条件：
1. 无序整数数组nums
2. 求数组中数位和相等的两个元素的和的最大值
3. 不存在这样的下标对，返回-1
隐藏条件：
1，可能不存在数位和相等的下标对
2. 数位和计算方法：循环求和
3. 双变量问题，可以枚举右边维护左边，在右边确定数位和，维护左边数位和相等的最大数
突破口：枚举右边，维护左边-> 循环算右边元素的数位和，更新ans -> 维护左边的数位和相等最大值 -> 如果ans<0 说明没找到数位和相等数对
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>mx(82,INT_MIN);
        int ans = 0;
        for(auto &i : nums)
        {
            int n = i;
            int cnt = 0;
            while(i)
            {
                cnt += i%10;
                i/=10;
            }
            ans = max(ans,mx[cnt] + n);
            mx[cnt] = max(mx[cnt],n);
        }
        if(ans == 0) ans = -1; 
        return ans;
    }
};
