#define ll long long
class Solution {
    int solve(vector<int>&arr,int index,int x,vector<vector<int>>&dp,int n){
    if(x==0){
        return 1;
    }
    if(index>=n || x<0){
        return 0;
    }
    if(dp[index][x]!=-1){
        return dp[index][x];
    }

    int ans =0;
    int nottake = solve(arr,index+1,x,dp,n);
    if(x-arr[index]>=0){
        ans = solve(arr,index,x-arr[index],dp,n);
    }
    return dp[index][x]=(ans+nottake);
}
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
            vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
            return solve(coins,0,amount,dp,n);
    }
};