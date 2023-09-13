class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;
        int front=0;
        int count=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                mp[s[i]]=true;
                count++;
            }
            else if(mp.count(s[i])==1){
                ans =max(count,ans);
                while(mp.count(s[i])==1){
                    mp.erase(s[front]);
                    front++;
                    count--;
                }
                count++;
                mp[s[i]]=true;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};