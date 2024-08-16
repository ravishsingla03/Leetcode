class Solution {
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row>=grid.size() || col>=grid[0].size()){
            return 1e9;
        }
        if(row==grid.size()-1 && col==grid[0].size()-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down =  solve(row+1,col,grid,dp) + grid[row][col];
        int right  = solve(row,col+1,grid,dp) + grid[row][col];
        
        return dp[row][col] = min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0,0,grid,dp);
    }
};