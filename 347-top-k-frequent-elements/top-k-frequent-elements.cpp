class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<vector<int>>count(nums.size()+1);
        for(auto i: mp){
            count[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(int i=nums.size();i>=0;i--){
            if(ans.size()==k){
                return ans;
            }
            if(count[i].size()>0){
                for(auto j: count[i]){
                    if(ans.size()!=k){
                        ans.push_back(j);
                    }
                }
            }
        }
        return ans;
    }
};