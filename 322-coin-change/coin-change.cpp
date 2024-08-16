class Solution {
    int solve(vector<int>&coins,int sum,int index,vector<vector<int>>&dp){
        if(sum==0){
            return 0;
        }
        if(index==coins.size() || sum<0){
            return INT_MAX;
        }
        if(dp[sum][index]!=-1){
            return dp[sum][index];
        }
        int pick = solve(coins,sum - coins[index],index,dp);
        if(pick!=INT_MAX){
            pick = pick +1;
        }
        int notp = 0 + solve(coins,sum,index+1,dp);
        return dp[sum][index]=min(pick,notp);
        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        int x =  solve(coins,amount,0,dp);
        if(x!=INT_MAX){
            return x;
        }
        else{
            return -1;
        }
    }
};