class Solution {
    bool solve(vector<int>&nums,int index,vector<int>&dp){
        int n =nums.size();
        if(index==n-1){
            return true;
        }
        if(index>=n){
            return false;
        }
        if(nums[index]==0){
            return false;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        bool ans = false;
        for(int i=1;i<=nums[index];i++){
            ans = ans || solve(nums,index+i,dp);
            if(ans){
                break;
            }
        }
        return dp[index]=ans;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};