class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first =edges[0][0];
        int second =edges[0][1];
        int x=edges[1][0];
        int y=edges[1][1];
        if(x==first){
            return x;
        }
        else if(x==second){
            return x;
        }
        else{
            return y;
        }
    }
};