class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,set<pair<int,int>>>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x = nums[i]*nums[j];
                    mp[x].insert({nums[i],nums[j]});
                
            }
        }
        int count=0;
        for(auto i: mp){
            if(i.second.size()>1){
                int n = i.second.size();
                count += 8*((n)*(n-1))/2;
            }
        }

        return count;
    }
};