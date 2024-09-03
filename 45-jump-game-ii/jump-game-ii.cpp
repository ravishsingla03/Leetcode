class Solution {
     int solve(vector<int>&nums,int index,vector<int>&dp){
        int n =nums.size();
        if(index==n-1){
            return 0;
        }
        if(index>=n){
            return nums.size()+1;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        int ans =nums.size() + 1;
        for(int i=nums[index];i>=1;i--){
            int temp = 1 + solve(nums,index + i,dp);
            ans = min(ans,temp);

        }
        return dp[index]=ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};