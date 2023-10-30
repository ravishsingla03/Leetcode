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
        for(int i=0;i<arr.size();i++){
            int x = __builtin_popcount(arr[i]);
            v.push_back({x,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto i: v){
            ans.push_back(i[1]);
        }
        return ans;
    }
};