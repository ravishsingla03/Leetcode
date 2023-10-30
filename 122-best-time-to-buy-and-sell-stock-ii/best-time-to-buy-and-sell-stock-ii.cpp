class Solution {
    int solve(vector<int>&prices,int index,int buy, vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        int ans=0;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy){
            //sell or ignore
            int sell = +prices[index] + solve(prices,index+1,0,dp);
            int ignore = 0 + solve(prices,index+1,1,dp);
            ans = max(sell,ignore); 
        }
        else{
            //buy or ignore
            int buy = -prices[index]+solve(prices,index+1,1,dp);
            int ignore = 0 + solve(prices,index+1,0,dp);
            ans = max(buy,ignore); 
        }
        return dp[index][buy]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,buy,dp);
    }
};