class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int  m =grid.size();
        int  n =grid[0].size();
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        int ans =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp =q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                //right
                cout<<i<<"->"<<j<<" ";
                if(j+1<n && grid[i][j+1]==1){
                    q.push(make_pair(i,j+1));
                    grid[i][j+1]=2;
                }
                // left
                if(j-1>=0 && grid[i][j-1]==1){
                    q.push(make_pair(i,j-1));
                    grid[i][j-1]=2;
                }
                //down
                if(i+1<m && grid[i+1][j]==1){
                    q.push(make_pair(i+1,j));
                    grid[i+1][j]=2;
                }
                //up
                if(i-1>=0 && grid[i-1][j]==1){
                    q.push(make_pair(i-1,j));
                    grid[i-1][j]=2;
                }
            }
            ans++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans-1;
    }
};