class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m,vector<int>(n,0));
        for(int i=0;i<walls.size();i++){
            matrix[walls[i][0]][walls[i][1]]=2;
        }
        for(int i=0;i<guards.size();i++){
            matrix[guards[i][0]][guards[i][1]]=3;
        }
        
        for(int i=0;i<guards.size();i++){
            int row = guards[i][0];
            int col = guards[i][1];
            //up
            row--;
            while(row>=0 && matrix[row][col]!=2 && matrix[row][col]!=3){
                matrix[row][col]=-1;
                row--;
            }
            //down
            row = guards[i][0];
            col = guards[i][1];
            row++;
            while(row<m && matrix[row][col]!=2 && matrix[row][col]!=3){
                matrix[row][col]=-1;
                row++;
            }
            //left
            row = guards[i][0];
            col = guards[i][1];
            col++;
            while(col<n && matrix[row][col]!=2 && matrix[row][col]!=3){
                matrix[row][col]=-1;
                col++;
            }
            //right
            row = guards[i][0];
            col = guards[i][1];
            col--;
            while(col>=0 && matrix[row][col]!=2 && matrix[row][col]!=3){
                matrix[row][col]=-1;
                col--;
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};