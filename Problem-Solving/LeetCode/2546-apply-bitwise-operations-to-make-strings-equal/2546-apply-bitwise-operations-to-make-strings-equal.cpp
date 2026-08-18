class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int len = s.length();
        int sonelen = 0;
        int tonelen = 0;
        for (auto c : s) {
            if (c == '1') sonelen++;
        }
        for (auto c : target) {
            if (c == '1') tonelen++;
        }
        if(sonelen > 0 && tonelen == 0) return false;
        if(sonelen == 0 && tonelen > 0) return false;
        return true;
    }
};