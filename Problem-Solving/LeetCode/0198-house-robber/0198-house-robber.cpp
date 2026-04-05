class Solution {
public:
    int dp[100];
    int size;
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        size = nums.size();
        return max(maxAmount(nums, 0), max(maxAmount(nums, 1), maxAmount(nums, 2)));
    }
    int maxAmount(vector<int>& nums, int idx) {
        if(idx>=size) return 0;
        
        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = nums[idx];
        return ret += max(maxAmount(nums, idx+2), maxAmount(nums, idx+3));
    }
};