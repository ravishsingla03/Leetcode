class Solution {
    int solve(vector<int>&cost,int n ,vector<int>&dp){
        if(n==0){
            return cost[0];
        }
        if(n==1)
            return cost[1];
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp)) + cost[n];
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        int n=cost.size();
        int ans  =min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};