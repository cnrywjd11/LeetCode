int dp[101][3];

int tra(vector<int>& nums, int idx, int start) {
    if (idx >= nums.size()) return 0;
    if (idx == nums.size()-1 && start == 0) return 0;
    int& ret = dp[idx][start];
    if (ret != -1) {
        return ret;
    }
    ret = nums[idx];
    ret += max(tra(nums, idx + 2, start), tra(nums, idx + 3, start));
    return ret;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(tra(nums, 0, 0), max(tra(nums, 1, 1), tra(nums, 2, 2)));
    }
};