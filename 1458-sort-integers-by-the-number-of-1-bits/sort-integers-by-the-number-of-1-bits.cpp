class Solution {
    int solve(int x){
        int count=0;
        while(x>0){
            if(x&1){
                count++;
            }
            x=x>>1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>v;
        map<int,vector<int>> mp;

        for(int i=0;i<arr.size();i++){
            int x = __builtin_popcount(arr[i]);
            mp[x].push_back(arr[i]);
            // v.push_back({x,arr[i]});
        }
        vector<int>ans;
        for(auto i: mp){
            vector<int>temp;
            temp = i.second;
            sort(temp.begin(),temp.end());
            for(auto j : temp){
                ans.push_back(j);
            }
        }
        return ans;
    }
};