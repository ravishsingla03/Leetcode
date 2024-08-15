class Solution {
    int solve(string w1,string w2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1==w1.size()){
            return w2.size()-ind2;
        }
        if(ind2==w2.size()){
            return w1.size()-ind1;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(w1[ind1]==w2[ind2]){
            return solve(w1,w2,ind1+1,ind2+1,dp);
        }
        else{

        //delete
        int del = 1 + solve(w1,w2,ind1+1,ind2,dp);
        //replace
        int rep = 1 + solve(w1,w2,ind1+1,ind2+1,dp);
        //insert
        int ins = 1 + solve(w1,w2,ind1,ind2+1,dp);
        return dp[ind1][ind2]=min(del,min(rep,ins));
        }
    }
public:
    int minDistance(string w1, string w2) {
        vector<vector<int>>dp(w1.size(),vector<int>(w2.size(),-1));
        return solve(w1,w2,0,0,dp);
    }
};