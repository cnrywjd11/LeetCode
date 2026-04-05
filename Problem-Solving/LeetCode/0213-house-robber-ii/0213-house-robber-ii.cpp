class Solution {
public:
    int dp[101][2];
    int size;
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        size = nums.size();
        return max(max(maxMoney(nums, 0, 1), maxMoney(nums, 1, 0)), max(maxMoney(nums, 2, 1), maxMoney(nums, 2, 0)));
    }
    int maxMoney(vector<int>& nums, int idx, int FirstSelectOption) {
        if(size==1) return nums[0];
        if(idx>=size) return 0;
        if(idx==size-1 && FirstSelectOption) return 0;

        int& ret = dp[idx][FirstSelectOption];
        if (ret != -1) return ret;

        ret = nums[idx];
        return ret += max(maxMoney(nums, idx+2, FirstSelectOption), maxMoney(nums, idx+3, FirstSelectOption));
    }
};