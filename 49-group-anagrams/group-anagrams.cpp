class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>copy = strs;
        int n = strs.size();
        for(int i =0;i<n;i++){
            sort(copy[i].begin(),copy[i].end());
        }
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
           mp[copy[i]].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i: mp){
            vector<string>temp;
            for(auto j: i.second){
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};