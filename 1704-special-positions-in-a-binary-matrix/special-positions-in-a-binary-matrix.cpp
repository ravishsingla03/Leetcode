class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>onerow(row,0);
        vector<int>onecol(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    onerow[i]++;
                    onecol[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && onerow[i]==1 && onecol[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};