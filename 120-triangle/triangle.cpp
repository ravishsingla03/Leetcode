class Solution {
    int solve(vector<vector<int>>&triangle , int i, int j, vector<vector<int>>&dp){
        if(i>=triangle.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]  = triangle[i][j] + min(solve(triangle,i+1,j,dp),solve(triangle,i+1,j+1,dp)); 
        return dp[i][j];
    }
    int solveTab(vector<vector<int>>&triangle){
        int n =triangle.size();
        int m = triangle.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =n-1;i>=0;i--){
            for(int j =i;j>=0;j--){
                dp[i][j]  = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]); 
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        int m = triangle.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(triangle,0,0,dp);
        return solveTab(triangle);

    }
};