class Solution {

    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==s1.size()){
            return s2.substr(j)==s3.substr(k);
        }
        if(j==s2.size()){
            return s1.substr(i)==s3.substr(k);
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }

        if(s1[i]==s3[k] && s2[j]!=s3[k]){
            return dp[i][j][k] =  solve(s1,s2,s3,i+1,j,k+1,dp);
        }

        if(s2[j]==s3[k] && s1[i]!=s3[k]){
            return dp[i][j][k] =solve(s1,s2,s3,i,j+1,k+1,dp);
        }

        if(s2[j]==s3[k] && s1[i]==s3[k]){
            return dp[i][j][k] =solve(s1,s2,s3,i,j+1,k+1,dp) || solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        return dp[i][j][k] =false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};