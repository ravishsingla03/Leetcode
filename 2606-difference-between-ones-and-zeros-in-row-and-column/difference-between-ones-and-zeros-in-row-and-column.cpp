class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>onerow(row,0);
        vector<int>onecol(col,0);
        vector<int>zerocol(col,0);
        vector<int>zerorow(row,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    onerow[i]++;
                    onecol[j]++;
                }
                else{
                    zerorow[i]++;
                    zerocol[j]++;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                grid[i][j]=onerow[i] + onecol[j] - zerorow[i] - zerocol[j];
            }
        }
        return grid;
    }
};