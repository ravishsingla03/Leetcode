class Solution {
    int solve(vector<int>&nums,int index,int prev,vector<vector<int>>&dp){
        if(index ==nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev]){
            pick = 1 + solve(nums,index+1,index,dp);
        }
        int notp = solve(nums,index+1,prev,dp);
        return dp[index][prev+1]=max(pick ,notp); 
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};