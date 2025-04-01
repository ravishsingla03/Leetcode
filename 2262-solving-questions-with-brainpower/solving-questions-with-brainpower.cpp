class Solution {
    long long solve(int index,vector<vector<int>>&q,vector<long long>&dp){
        int n = q.size();
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        long long pick = q[index][0] + solve(index+1+q[index][1],q,dp);
        long long notpick = 0 + solve(index+1,q,dp);
        return dp[index]=max(pick,notpick);
    }

    long long solvetab(vector<vector<int>>&q){
        vector<long long>dp(q.size()+1,0);
        int n = q.size();
        for(int i=n-1;i>=0;i--){
            long long pick =q[i][0];
            if(i+1+q[i][1]<n){
                 pick += dp[i+1+q[i][1]];
            }

            long long notpick = 0 + dp[i+1];
            
            dp[i]=max(pick,notpick);
        }
        return dp[0];
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        // vector<long long>dp(q.size(),-1);
        return solvetab(q);
        // return solve(0,q,dp);
    }
};