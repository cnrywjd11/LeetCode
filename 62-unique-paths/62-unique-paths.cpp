int dp[101][101];

class Solution {
public:
    int trav(int y, int x) {
        if (y == 0 && x == 0) return 1;
        
        int& ret = dp[y][x];
        if (ret != -1) return ret;
        
        ret = 0;
        if (y > 0) ret += trav(y-1, x);
        if (x > 0) ret += trav(y, x-1);
        
        return ret;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return trav(m-1, n-1);
    }
};