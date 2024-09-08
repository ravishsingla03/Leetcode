class Solution {
    int solve(string s , int index,vector<int>&dp){

        if(index==s.size()){
            return 1;
        }
        if(index<s.size() && s[index]=='0'){
            return 0;
        }
        if(index>s.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=0;
        int x = s[index] -'0';
        if(x<=26){
            ans+=solve(s,index+1,dp);
        }
        int y = (s[index] -'0')*10 + s[index+1]-'0';
        if(y <=26){
            ans+=solve(s,index+2,dp);
        }
        return dp[index]=ans;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);

        return solve(s,0,dp);
    }
};