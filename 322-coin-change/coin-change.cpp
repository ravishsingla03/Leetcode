class Solution {
    int solve(vector<int>&coins ,int sum,vector<int>&dp){
        if(sum==0){
            return 0;
        }
        if(sum <0){
            return INT_MAX;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans = INT_MAX;
        for(int i =0;i<coins.size();i++){
            int x = solve(coins,sum - coins[i],dp);
            if(x!=INT_MAX){
                ans = min(ans,x+1);
            }
        }
        return dp[sum]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        return solve(coins,amount,dp)!=INT_MAX ? solve(coins,amount,dp) : -1;
    }
};