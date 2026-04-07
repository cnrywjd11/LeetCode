class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());
        
        int size = nums.size();
        int maxSeq = 1;
        int len = 1;
        for(int i=1;i<size;i++) {
            if(nums[i] - nums[i-1] == 1) {
                len++;
                maxSeq = max(maxSeq, len);
            } else {
                len = 1;
            }
        }
        return maxSeq;
    }
};