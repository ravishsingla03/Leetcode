class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>&dfsvis,unordered_map<int,vector<int>>&adj){
        vis[node]=1;
        dfsvis[node]=1;

        bool ans =false;
        for(auto neighbour: adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour,vis,dfsvis,adj)){
                    return true;
                }
            }
            else if(dfsvis[neighbour]){
               return true;
            }
        }
        dfsvis[node]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>>adj;
        for(auto i: p){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj)==true){
                    return false;
                }
            }
        }
        return true;
    }
};