class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>copy = matrix;
        int row = matrix.size();
        int col =matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int curr_row=row-1;
                int curr_col=col-1;
                if(matrix[i][j]==0 && copy[i][j]==0){
                    cout<<curr_col<<" "<<curr_row;
                    while(curr_row>=0){
                        matrix[curr_row][j]=0;
                        curr_row--;
                    }
                    while(curr_col>=0){
                        matrix[i][curr_col]=0;
                        curr_col--;
                    }
                }
            }
        }
    }
};