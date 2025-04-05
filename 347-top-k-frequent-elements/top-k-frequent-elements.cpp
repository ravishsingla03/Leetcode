class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};