class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>mp;
        for(int i =0;i<n;i++){
            mp.push_back({nums[i],i});
        }

        sort(mp.begin(),mp.end());

        vector<vector<pair<int,int>>>grp;
        grp.push_back({mp[0]});
        for(int i=1;i<n;i++){
            if(mp[i].first-mp[i-1].first<=limit){
                grp.back().push_back(mp[i]);
            }
            else{
                grp.push_back({mp[i]});
            }
        }

        for(auto i: grp){
            vector<int>ind;
            for(auto j:i){
                ind.push_back(j.second);
            }
            sort(ind.begin(),ind.end());

            for(int j=0;j<ind.size();j++){
                nums[ind[j]]= i[j].first;
            }
        }

        


        return nums;
    }
};