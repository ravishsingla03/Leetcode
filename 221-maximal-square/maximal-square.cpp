class Solution {
    int solve(vector<vector<char>>& matrix, int row,int col , int &maxi ,vector<vector<int>>&dp){
        if(row>=matrix.size() || col>=matrix[0].size()){
            return 0;
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int right = solve(matrix,row,col+1,maxi,dp);
        int diagonal = solve(matrix,row+1,col+1,maxi,dp);
        int down = solve(matrix,row+1,col,maxi,dp);

        if(matrix[row][col]=='1'){
            dp[row][col] = 1+ min(right,min(diagonal,down));
            maxi = max(dp[row][col],maxi);
            return dp[row][col];
        }
        else{
            return dp[row][col]=0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi =0;
        vector<vector<int>> dp ( matrix.size(), vector<int>(matrix[0].size(),-1) );
        int ans = solve(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};