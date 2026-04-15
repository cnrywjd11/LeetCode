class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>> pq;
        for(auto& interval : intervals) {
					int starti = interval[0], endi = interval[1];
					pq.push({-endi, -starti});
        }
      	int curStarti = -50001, curEndi = -50001;
      	int sum = 0;
        while(pq.size()) {
        	auto front = pq.top();
          pq.pop();
          int starti = -front.second, endi = -front.first;
          if(curEndi <= starti) {
            curStarti = starti, curEndi = endi;
          } else {
            sum++;
          }
        }
        return sum;
    }
};