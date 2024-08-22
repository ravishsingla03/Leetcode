class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>&dfsvis,unordered_map<int,vector<int>>&adj,stack<int>&st){
        vis[node]=1;
        dfsvis[node]=1;


        for(auto neighbour: adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour,vis,dfsvis,adj,st)){
                    return true;
                }
            }
            else if(dfsvis[neighbour]){
               return true;
            }
        }
        dfsvis[node]=0;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>>adj;
        for(auto i: p){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj,st)==true){
                    return {};
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};