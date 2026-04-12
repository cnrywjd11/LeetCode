class Solution {
public:
    string longestPalindrome(string s) {
        int ml=0, mr = 0;
        for(int i=0;i<s.size();i++) {
            int rl=0, rr=0;
            longestPalindromeWithIdx(s, i, i, &rl, &rr);
            if(mr-ml < rr-rl) {
                ml = rl;
                mr = rr;
            }
        }
        for(int i=0;i<s.size()-1;i++) {
            int rl=0, rr=0;
            longestPalindromeWithIdx(s, i, i+1, &rl, &rr);
            if(mr-ml < rr-rl) {
                ml = rl;
                mr = rr;
            }
        }
        return s.substr(ml, mr-ml+1);
    }

    void longestPalindromeWithIdx(string s, int l, int r, int* rl, int* rr) {
        do {
            if(s[l] == s[r]) {
                *rl = l, *rr = r;
                l--;
                r++;
            } else {
                break;
            }
        } while(0<=l && r<s.size());
    }
};