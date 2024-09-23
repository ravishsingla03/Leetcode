class Solution {
    int solve(int n , int i,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }

        if(i*i>n){
            return 1e9;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        int pick = 1 + solve(n-i*i,i,dp);
        int npick = solve(n,i+1,dp);
        return dp[n][i]=min(pick,npick);
    }
public:
    int numSquares(int n) {
        vector<vector<int>>dp(n+1,vector<int>(sqrt(n)+1,-1));
        return solve(n,1,dp);
    }
};