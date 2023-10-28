class Solution {
    int solve(string w1,string w2 ,int i,int j,vector<vector<int>>&dp){
        if(i==w1.length()){
            return w2.length()-j;
        }
        if(j==w2.length()){
            return w1.length()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans =0;
        if(w1[i]==w2[j]){
            return solve(w1,w2,i+1,j+1,dp);
        }
        else{
            //insert
            int a = 1 + solve(w1,w2,i,j+1,dp);

            //delete
            int b = 1 + solve(w1,w2 , i+1,j,dp);

            //replace
            int c = 1 +  solve(w1,w2 , i+1,j+1,dp);

            ans = min(a,min(b,c));
        }
        return dp[i][j]=ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};