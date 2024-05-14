class Solution {
    int solve(int i,int j,int m ,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = solve(i+1,j,m,n,dp);
        int right = solve(i,j+1,m,n,dp);
        int ans =down + right;
        
        return dp[i][j]=ans;

    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
        // if(m==1 && n==1){
        //     return num;
        // }
        return dp[0][0];
    }
};