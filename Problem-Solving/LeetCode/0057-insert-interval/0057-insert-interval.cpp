class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        if (len == 0) {
            return vector<vector<int>> {newInterval};
        }
        vector<vector<int> > output;
        int idx = 0;

        for (;idx < len && intervals[idx][1] < newInterval[0];idx++) {
            output.push_back(intervals[idx]);
        }

        for(;idx < len && intervals[idx][0] <= newInterval[1];idx++) {
            newInterval[0] = min(intervals[idx][0], newInterval[0]);
            newInterval[1] = max(intervals[idx][1], newInterval[1]);
        }
        output.push_back(newInterval);

        for(;idx < len;idx++) {
            output.push_back(intervals[idx]);
        }

        return output;
    }
};