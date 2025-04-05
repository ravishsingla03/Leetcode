class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string,vector<int>>mp;
        for(int i =0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
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