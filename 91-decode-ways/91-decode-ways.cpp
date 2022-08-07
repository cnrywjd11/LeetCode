int dp[102];

int sol(string s, int idx) {
    if (s[idx] == '0') return 0;
    if (idx >= s.length()) return 0;
    
    int& ret = dp[idx];
    if (ret != -1){
        return ret;
    }
    
    ret = 0;
 
    if (idx + 2 < s.length()) {
        ret = sol(s, idx+1);
        
        int c1 = s[idx] - '0';
        int c2 = s[idx+1] - '0';
        if (c1 == 1 || (c1 == 2 && 0 <= c2 && c2 <= 6)) ret += sol(s, idx+2);
        return ret;
    } else {
        if (idx == s.length() -1) {
            return ret = 1;
        } else {
            int c1 = s[idx] - '0';
            int c2 = s[idx+1] - '0';
            if (c2 != 0) ret++;
            if (c1 == 1) ret++;
            if (c1 == 2 && 0 <= c2 && c2 <= 6) ret++;
            return ret;
        }
    }
}

class Solution {
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return sol(s, 0);
    }
};