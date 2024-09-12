class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<int,int>mp;
        for(auto i: allowed){
            mp[i-'a']++;
        }
        int count=0;
        for(auto i: words){
            int flag=0;
            for(auto j:i ){
                if(mp.count(j-'a')==0){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                count++;
            }
        }
        return count;
    }
};