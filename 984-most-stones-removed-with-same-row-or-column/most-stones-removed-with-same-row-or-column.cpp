class Solution {
    void dfs(int index , vector<vector<int>>&stones,vector<int>&vis){
        vis[index]=1;
        int n =stones.size();

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(stones[i][0]==stones[index][0]){
                    dfs(i,stones,vis);
                }
                if(stones[i][1]==stones[index][1]){
                    dfs(i,stones,vis);
                }
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int ans =0;
        vector<int>vis(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,vis);
            }
            else
                ans++;
        }
        return ans;
    }
};