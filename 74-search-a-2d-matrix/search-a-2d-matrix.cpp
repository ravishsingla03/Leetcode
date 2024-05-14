class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j = matrix.size()*matrix[0].size() -1 ;
        int row =matrix.size();
        int col =matrix[0].size();
        while(i<=j){
            int mid = i + (j-i)/2;
            int x = matrix[mid/col][mid%col];
            if(x==target){
                return true;
            }
            else if(x > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return false;
    }
};