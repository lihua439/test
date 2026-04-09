/*1695. 删除子数组的最大得分
已解答
中等
相关标签
premium lock icon
相关企业
提示
给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>s;
        int left = 0;
        int ans = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            if(!s.count(nums[right]))
            {
                s.insert(nums[right]);
            }
            else{
                while(s.count(nums[right]))
                {
                    s.erase(nums[left]);
                    sum-=nums[left];
                    left++;
                }
                s.insert(nums[right]);
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};
