class Solution {
    bool solve(vector<int>&nums,int total,int index,int sum,bool &ans,vector<vector<int>>&dp){
        if(sum==total/2){
            return true;
        }
        if(index==nums.size()){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool take =false;
        for(int i = index; i<nums.size();i++){
            take = take || solve(nums,total,i+1,sum + nums[i],ans,dp);
        }

        return dp[index][sum] = take;
    }
public:
    bool canPartition(vector<int>& nums) {
        bool ans =false;
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }

        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return solve(nums,sum,0,0,ans,dp);

    }
};