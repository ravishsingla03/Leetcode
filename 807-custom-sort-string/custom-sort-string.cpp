class Solution {
public:
    string customSortString(string order, string s) {
        // int ord_count[26]={0};
        // int s_count[26]={0};
        // for(auto i: order){
        //     ord_count[i-'a']++;
        // }
        // for(auto i: order){
        //     s_count[i-'a']++;
        // }
        string ans="";
        // for(int i=0;i<26;i++){
            
        // }
        map<char,int>mp;
        int count=0;
        for(auto i:order){
            mp[i]=count++;
        }
        vector<int>rav;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                rav.push_back(mp[s[i]]);
            }
            else{
                ans+=s[i];
            }
        }
        sort(rav.begin(),rav.end());
        string sortans="";
        for(auto i:rav){
            sortans +=order[i];
        }
        return sortans+ans;
    }
};