class Solution {
    int solve(vector<int>&arr,int start,unordered_map<int,vector<int>>&mp,vector<int>&vis ){
 
        vis[start] =1;
        queue<pair<int,int>>q;
        q.push({start,0});

        while(!q.empty()){
            int index = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(index==arr.size()-1){
                return steps;
            }
            if(index-1>=0 && !vis[index-1]){
                q.push({index-1,steps +1});
                vis[index-1]=1;
            }
            if(index+1<arr.size() && !vis[index+1]){
                q.push({index+1,steps +1});
                vis[index+1]=1;
            }
            for(int k =mp[arr[index]].size()-1;k>=0;k--){
                int i = mp[arr[index]][k];
                if(i!=index && !vis[i]){
                    q.push({i,steps +1});
                    vis[i]=1;
                }
            }
            mp[arr[index]].clear();
        }
        return 0;
    }
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(arr.size(),0);
        return solve(arr,0,mp,vis);
    }
};