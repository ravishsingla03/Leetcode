class Solution {
    bool solve(vector<int>&arr,int start,vector<int>&vis){
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index]==0){
                return true;
            }
            int newind1 = index + arr[index];
            if(newind1>=0 && newind1<arr.size() && !vis[newind1]){
                q.push(newind1);
                vis[newind1]=1;
            }
            int newind2 = index - arr[index];
            if(newind2>=0 && newind2<arr.size() && !vis[newind2]){
                q.push(newind2);
                vis[newind2]=1;
            }
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return solve(arr,start,vis);
    }
};