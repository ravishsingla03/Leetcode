class Solution {
    const int mod = 1e9 +7;
    int solve(int sum,int k,int index,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(sum<0 || pow(index,k)>sum){
            return 0;
        }
        if(dp[sum][index]!=-1){
            return dp[sum][index];
        }
        long long int ans =0;

        ans= solve(sum,k,index+1,dp)%mod + solve(sum-pow(index,k),k,index+1,dp)%mod;
        return dp[sum][index]=ans%mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,1,dp);
    }
};