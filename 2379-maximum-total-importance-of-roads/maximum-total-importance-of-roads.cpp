class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<int>>mp;
        for(auto i:roads){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        vector<int>arr(n,0);

        for(auto i: roads){
            arr[i[0]]++;
            arr[i[1]]++;
        }

        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push(make_pair(arr[i],i));
        }
        unordered_map<int,int>ans;
        while(!q.empty()){
            ans[q.top().second] = n;
            n--;
            q.pop();
        }
        long long int fans =0;
        for(auto i: roads){
            fans  = fans + ans[i[0]] + ans[i[1]];
        }
        return fans;
    }
};