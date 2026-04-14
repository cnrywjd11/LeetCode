class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> keys = strs;
        for(int i=0;i<keys.size();i++) {
            sort(keys[i].begin(), keys[i].end());
        }
        unordered_map<string, vector<string>> m;
        for(int i=0;i<keys.size();i++) {
            auto it = m.find(keys[i]);
            m[keys[i]].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto it : m) {
            ret.push_back(it.second);
        }
        return ret;
    }
};