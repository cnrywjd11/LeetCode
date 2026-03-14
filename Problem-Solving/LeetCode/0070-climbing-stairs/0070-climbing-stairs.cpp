class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        memset(dp, -1, sizeof(dp));
        return dw(n, dp);
    }
    int dw(int n, int dp[]) {
        if (n <=2) return n; 
        int &ret = dp[n];
        if (ret != -1) {
            return ret;
        }
        return ret = dw(n-1, dp) + dw(n-2, dp);
    }
};