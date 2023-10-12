class Solution {
    int solve(vector<int>& nums,int n,vector<int>&dp){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int inc = solve(nums,n-2,dp)+nums[n];
        int exc = solve(nums,n-1,dp);

        dp[n] = max(inc,exc);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>v1;
        vector<int>v2;
        int n =nums.size();
        vector<int>dp(n+1,-1);
        for(int i=1;i<n;i++){
            v1.push_back(nums[i]);
        }
        for(int i=0;i<n-1;i++){
            v2.push_back(nums[i]);
        }
        int ans1 = solve(v1,n-2,dp);
        vector<int>dp2(n+1,-1);
        int ans2 = solve(v2,n-2,dp2);

        return max(ans1,ans2);

    }
};