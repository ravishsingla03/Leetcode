class Solution {
    int solve(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick = nums[index]+ solve(index+2,nums,dp);
        int npick = 0+ solve(index+1,nums,dp);
        return dp[index]=max(pick,npick);
    }
    int solve1(int index,vector<int>&nums,vector<int>&dp1){
        // cout<<index<<" ";
        if(index>=nums.size()){
            return 0;
        }if(dp1[index]!=-1){
            return dp1[index];
        }
        int pick = nums[index]+ solve1(index+2,nums,dp1);
        int npick = 0+ solve1(index+1,nums,dp1);
        return dp1[index]=max(pick,npick);
    }
public:
    int rob(vector<int>& nums) {
        // cout<<solve1(1,nums);
        vector<int>dp(nums.size(),-1);
        vector<int>dp1(nums.size(),-1);
        return max(nums[0] + solve(2,nums,dp),solve1(1,nums,dp1));
    }
};