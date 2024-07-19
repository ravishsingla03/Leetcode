class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {

        vector<pair<int,int>>mini;
        vector<pair<int,int>>maxi;
        for(int i=0;i<mat.size();i++){
            int x =0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][x]>mat[i][j]){
                    x = j;
                }
            }
            mini.push_back({i,x});
        }

        for(int i=0;i<mat[0].size();i++){
            int x= 0;
            for(int j=0;j<mat.size();j++){
                 if(mat[x][i]<mat[j][i]){
                    x = j;
                }
            }
            maxi.push_back({x,i});
        }
        vector<int>ans;
        for(auto i : maxi){
            for(auto j: mini){
                if(i==j){
                    ans.push_back(mat[i.first][i.second]);
                }
            }
        }
        return ans;
    }
};