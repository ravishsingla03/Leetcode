class Solution {
    bool solve(vector<vector<int>>grid,int row,int col){
        int temp=0;
        unordered_map<int,int>mp;
        for(int i=row;i<row+3;i++){
            int sum1=0;
            int sum2=0;
            for(int j=col;j<col+3;j++){
                sum1 += grid[i][j];
                if(grid[i][j]>9 || grid[i][j]<1 ||mp.count(grid[i][j])!=0){
                    return false;
                }
                mp[grid[i][j]]=1;
            }
            if(temp!=0 && temp!=sum1 &&temp!=sum2){
                return false;
            }
            else{
                temp = sum1;
            }
        }
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != temp){
            return false;
        }
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != temp){
            return false;
        }
            for(int j=col;j<col+3;j++){
            int sum2=0;
        for(int i=row;i<row+3;i++){
                sum2 += grid[i][j];
            }
            if(temp!=sum2){
                return false;
            }
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3){
            return 0;
        }
        int m =grid.size();
        int n =grid[0].size();
        int count=0;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(solve(grid,i,j))
                    count++;
            }
        }
        // cout<<x;
        return count;
    }
};