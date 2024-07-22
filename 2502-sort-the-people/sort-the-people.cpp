class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        unordered_map<int,int>mp;
        int j=0;
        for(auto i:h){
            mp[i]=j++;
        }
        vector<string>ans=names;
        sort(h.begin(),h.end(),greater<>());
        for(int i=0;i<ans.size();i++){
            ans[i]=names[mp[h[i]]];
        }
        return ans;
    }
};