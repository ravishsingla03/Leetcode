class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i =0,j=0;
        int n =s.size();
        int ans =0;
        while(j<n){
            if(mp.count(s[j])!=0){
                ans = max(ans,j-i);
                while(mp.count(s[j])!=0){
                    mp.erase(s[i]);
                    i++;
                }
            }
            mp[s[j]]=1;
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};