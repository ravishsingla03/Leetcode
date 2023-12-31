class Solution {
    const int mod = (int)pow(10, 9) + 7;
    int solve(int n ,int k, int target,vector<vector<int>>&dp){
        if(n==0 && target>0){
            return 0;
        }
        if(target==0 && n==0){
            return 1;
        }
        else if(target<0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target]%mod;
        }
        int count=0;
        for(int i=1;i<=k;i++){
            count= count%mod + solve(n-1,k,target-i,dp)%mod;
        }
        return dp[n][target]=count%mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};