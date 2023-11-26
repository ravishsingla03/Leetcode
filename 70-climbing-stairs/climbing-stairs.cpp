class Solution {
    int solve(int& count,int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = solve(count,n-1,dp) + solve(count,n-2,dp);
        return dp[n]=ans;
    }

    int solveTab(int n){
        vector<int>dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {

        int count=0;
        vector<int>dp(n+1,-1);
        // return solve(count,n,dp);
        return solveTab(n);
        
    }
};