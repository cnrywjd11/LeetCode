class Solution {
public:
    string longestPalindrome(string s) {
        string longestStr="";
        for(int i=0;i<s.size();i++) {
            string tmpLongestStr = longestPalindromeWithIdx(s, i, i);
            if(longestStr.size() < tmpLongestStr.size()) {
                longestStr = tmpLongestStr;
            }
        }
        for(int i=0;i<s.size()-1;i++) {
            string tmpLongestStr = longestPalindromeWithIdx(s, i, i+1);
            if(longestStr.size() < tmpLongestStr.size()) {
                longestStr = tmpLongestStr;
            }
        }
        return longestStr;
    }

    string longestPalindromeWithIdx(string s, int l, int r) {
        string longestStr="";
        do {
            if(s[l] == s[r]) {
                longestStr = s.substr(l, r-l+1);
                l--;
                r++;
            } else {
                break;
            }
        } while(0<=l && r<s.size());
        return longestStr;
    }
};