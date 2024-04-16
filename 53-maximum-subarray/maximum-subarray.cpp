class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algorithm
        //take maxi =first elemnt
        //take sum +=nums[i]
        //if sum<0 then sum =0
        int maxi = nums[0];
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi = max(sum,maxi);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};