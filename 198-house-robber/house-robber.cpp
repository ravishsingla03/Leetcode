class Solution {
    int solve(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick = nums[index] + solve(index+2,nums,dp);
        int notpick = 0 + solve(index+1,nums,dp);

        return dp[index]=max(pick,notpick);
    }
    int solve1(vector<int>&nums){
        vector<int>dp(nums.size()+1,0);

        for(int i=0;i<nums.size();i++){
            int pick = nums[i];
            if(i>1){
                pick+= dp[i-2];
            }
            int notpick=0;
            if(i>0){
                notpick+=dp[i-1];
            }
            dp[i]=max(pick,notpick);
        }

        return dp[nums.size()-1];
    }
public:
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);

        // return solve(0,nums,dp);
        return solve1(nums);
    }
};