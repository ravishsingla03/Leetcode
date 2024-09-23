class Solution {
    int solve(string s , unordered_map<string,int>&mp,int index,vector<int>&dp){
        if(index==s.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = INT_MAX;
        string temp ="";
        for(int i = index;i<s.size();i++){
            temp+=s[i];
            if(mp.count(temp)!=0){
                ans = min(ans,solve(s,mp,i+1,dp));
            }
        }
        ans = min(ans,1 + solve(s,mp,index+1,dp));
        return dp[index]=ans;
    }
public:
    int minExtraChar(string s, vector<string>& dic) {
        unordered_map<string,int>mp;
        for(auto i: dic){
            mp[i]++;
        }
        vector<int>dp(51,-1);
        return solve(s,mp,0,dp);
    }
};