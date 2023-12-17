class Solution {
    int solve(vector<vector<int>>& grid, int i,int j,vector<vector<int>>&dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down  = solve(grid,i+1,j,dp)+grid[i][j];
        int left  = solve(grid,i,j+1,dp)+grid[i][j];
        return dp[i][j]=min(left,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid,0,0,dp);
    }
};