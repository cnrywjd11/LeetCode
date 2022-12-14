class Solution {
public:
    int dp[10001];
    
    int trav(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (idx == nums.size()-1) return 1;
        
        int& ret = dp[idx];
        if (ret != -1) return ret;
        
        ret = 0;
        if (idx + nums[idx] < nums.size() -1) {
            for(int i=nums[idx];i>=1;i--) {
                if (trav(nums, idx+i)) return ret = 1;
            }
        } else {
            return ret = 1;
        }
        
        
        return ret;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return trav(nums, 0);    
    }
};