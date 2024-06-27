class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first =edges[0][0];
        int second =edges[0][1];
        for(int i=1;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
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
        return -1;
    }
};