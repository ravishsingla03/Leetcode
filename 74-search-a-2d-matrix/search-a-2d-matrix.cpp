class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=0;
        for(int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if(target<matrix[i][j]){
                    return false;
                }
                if(target==matrix[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
};