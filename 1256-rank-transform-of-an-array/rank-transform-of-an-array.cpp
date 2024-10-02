class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>ans=arr;
        int count=1;
        for(auto i: mp){
            for(auto j:i.second){
                ans[j]=count;
            }
            count++;
        }
        return ans;
    }
};