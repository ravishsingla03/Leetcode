class Solution {
    int bfs(unordered_map<int,vector<int>>&mp,int n){
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=1;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(node==n-1){
                return dis;
            }

            for(auto i: mp[node]){
                if(!vis[i]){
                    q.push({i,dis+1});
                    vis[i]=1;
                }
            }
        }
        return 0;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[i].push_back(i+1);
        }

        vector<int>ans;
        for(int i=0;i<q.size();i++){
            mp[q[i][0]].push_back(q[i][1]);
            ans.push_back(bfs(mp,n));
        }
        return ans;
    }
};