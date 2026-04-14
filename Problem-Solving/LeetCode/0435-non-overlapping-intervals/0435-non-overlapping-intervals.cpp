class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>> pq;
        for(auto v : intervals) {
            pq.push({-v[1], -v[0]});
        }
        int curLeft = -50001, curRight = -50001;
        int ret = 0;
        while(pq.size()) {
            auto v = pq.top();
            pq.pop();
            int left = -v.second, right = -v.first;
            if(curRight <= left) {
                curLeft = left;
                curRight = right;
            } else {
                ret++;
            }
        }
        return ret;
    }
};