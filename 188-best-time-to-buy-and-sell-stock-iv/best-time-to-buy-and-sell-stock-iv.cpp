class Solution {
        int solve(vector<int>&prices,int index,int buy, vector<vector<vector<int>>>&dp,int limit){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        int ans=0;
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        if(buy){
            //sell or ignore
            int sell = +prices[index] + solve(prices,index+1,0,dp,limit-1);
            int ignore = 0 + solve(prices,index+1,1,dp,limit);
            ans = max(sell,ignore); 
        }
        else{
            //buy or ignore
            int buy = -prices[index]+solve(prices,index+1,1,dp,limit);
            int ignore = 0 + solve(prices,index+1,0,dp,limit);
            ans = max(buy,ignore); 
        }
        return dp[index][buy][limit]=ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,0,dp,k);
    }
};