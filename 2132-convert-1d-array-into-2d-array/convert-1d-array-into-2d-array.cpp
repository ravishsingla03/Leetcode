class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& orig, int m, int n) {
        vector<vector<int>>ans;
        if(m*n != orig.size()){
            return ans;
        }
        int k=0;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(orig[k++]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};