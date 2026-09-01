class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = s[0];
        vector<int> vt;
        vt.push_back(0);
        for(int i=1;i<s.length();i++) {
            char ch = s[i];
            if(ch == cur) continue;
            else {
                cur = ch;
                vt.push_back(i);
            }
        }
        vt.push_back(s.length());

        int sum = 0;
        for(int i=1;i<vt.size()-1;i++) {
            int len = min(vt[i]-vt[i-1], vt[i+1]-vt[i]);
            sum += len;
        }

        return sum;
    }
};