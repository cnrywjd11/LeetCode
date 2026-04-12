class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vt;
        sort(nums.begin(), nums.end());
        for(int j=1;j<nums.size()-1;j++) {
            int l=0, r=nums.size()-1;
            do {
                int sum = nums[l] + nums[j] + nums[r];
                if(sum > 0) {
                    r--;
                } else if(sum < 0) {
                    l++;
                } else {
                    vt.push_back({nums[l], nums[j], nums[r]});
                    l++;
                    r--;
                }
            } while(l < j && j < r);
        }
        sort(vt.begin(), vt.end());
        vt.erase(unique(vt.begin(), vt.end()), vt.end());
        return vt;
    }
};