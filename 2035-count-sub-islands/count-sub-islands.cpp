class Solution {
    bool bfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis){
        vis[i][j]=1;
        int n = grid2.size();
        int m = grid2[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});

        bool flag =true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(grid2[row][col]==1 && grid1[row][col]!=1){
                flag= false;
            }
            int arr1[] ={-1,0,1,0};
            int arr2[] ={0,1,0,-1};
            for(int k=0;k<4;k++){
                int newrow = row+arr1[k];
                int newcol = col+arr2[k];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && grid2[newrow][newcol]==1){
                    q.push({newrow,newcol});
                    vis[newrow][newcol]=1;
                }
            }
        }
        return flag;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& grid2[i][j]==1){
                    if(bfs(i,j,grid1,grid2,vis)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};