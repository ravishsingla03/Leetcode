class Solution {
    int solve(vector<int>& days, vector<int>& costs,int index,vector<int>&dp,int n){
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int one = costs[0]+solve(days,costs,index+1,dp,n);

        int i;
        for(i =index;i<n && days[i]<days[index]+7;i++);
        int seven = costs[1] + solve(days,costs,i,dp,n);

        for(i =index;i<n && days[i]<days[index]+30;i++);
        int thirty = costs[2] + solve(days,costs,i,dp,n);

         dp[index]  =min(one,min(thirty,seven));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        int ans = solve(days,costs,0,dp,n);
        return ans;
    }
};