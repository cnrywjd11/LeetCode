class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2);
        bool found = false;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i] + nums[j] == target) {
                    results[0] = i;
                    results[1] = j;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        return results;
    }
};