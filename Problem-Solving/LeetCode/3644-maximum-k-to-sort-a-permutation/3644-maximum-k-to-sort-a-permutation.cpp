class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int bitv = 131071;
        for (int i=0;i<nums.size();i++) {
            if(nums[i] != i) {
                bitv &= nums[i];
            }
        }
        return bitv == 131071 ? 0 : bitv;
    }
};