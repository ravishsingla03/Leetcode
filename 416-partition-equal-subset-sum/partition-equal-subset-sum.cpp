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
        
        vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2)+1,0));
        for(int i=0;i<=nums.size();i++) dp[i][0]=1;

        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<=sum/2;j++){
                int pick =0;
                if(j>=nums[i]){
                    pick =dp[i+1][j-nums[i]];
                }
                int notpick =dp[i+1][j];

                dp[i][j]=pick | notpick;
            }
        }
        return dp[0][sum/2];
    }
};