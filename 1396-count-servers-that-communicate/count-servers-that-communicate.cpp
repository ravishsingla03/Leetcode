class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        int n =grid.size();
        int m = grid[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int k = 0;
                    int count=0;
                    while(k<n && count<2){
                        if(grid[k][j]){
                            count++;
                        }
                        k++;
                    }
                    k=0;
                    int count2 = 0;
                    while(k<m && count2<2){
                        if(grid[i][k]){
                            count2++;
                        }
                        k++;
                    }
                    if(count==2 || count2==2){
                        ans++;
                    }
                }
            }
        }
        // for(auto i: row){
        //     cout<<i<<" ";
        // }
        return ans;
    }
};