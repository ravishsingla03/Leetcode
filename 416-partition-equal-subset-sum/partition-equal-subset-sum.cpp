class Solution {
    int solve(vector<int>&nums,int index,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        int pick =solve(nums,index+1,sum-nums[index],dp);
        int notpick =solve(nums,index+1,sum,dp);

        return dp[index][sum]=pick | notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums,0,sum/2,dp);
    }
};