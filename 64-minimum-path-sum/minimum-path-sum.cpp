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
        // return solve(0,0,grid,dp);
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==m-1 && j==n-1) 
                    dp[i][j] = grid[i][j];
                else{
                    int down = grid[i][j];
                    if(i<m-1){
                        down+= dp[i+1][j];
                    }
                    else{
                        down+=1e9;
                    }

                    int right=grid[i][j];
                    if(j<n-1){
                        right+=dp[i][j+1];
                    }
                    else{
                        right+=1e9;
                    }
                    dp[i][j] = min(down , right);
                }
            }
        }
        return dp[0][0];
    }
};