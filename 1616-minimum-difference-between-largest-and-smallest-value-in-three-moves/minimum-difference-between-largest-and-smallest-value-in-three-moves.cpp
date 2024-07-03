class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        int x = nums[nums.size()-1] - nums[3];
        int y = nums[nums.size()-2] - nums[2];
        int z = nums[nums.size()-3] - nums[1];
        int r = nums[nums.size()-4] - nums[0];
        return min(x,min(y,min(z,r)));
    }
};