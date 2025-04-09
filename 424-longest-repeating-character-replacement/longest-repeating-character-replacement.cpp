class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0;
        int i =0;
        int j=0;
        int n = s.size();
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            int len = j-i+1;
            int maxi=0;
            for(auto i: mp){
                maxi = max(maxi,i.second);
            }
            if(len-maxi<=k){
                ans = max(ans,len);
            }
            else{
                while(len-maxi>k){
                    mp[s[i]]--;
                    len = j-i;
                    int maxi=0;
                    for(auto i: mp){
                        maxi = max(maxi,i.second);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};