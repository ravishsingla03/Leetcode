class Solution {
    int solve(int index , vector<int>&arr,int k,vector<int>&dp){
        if(index==arr.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int len=0;
        int maxSum =INT_MIN;
        int maxi =INT_MIN;
        for(int j=index;j<arr.size() && j < index+k;j++){
            len++;
            maxi =max(maxi,arr[j]);
            int sum = maxi * len + solve(j+1,arr,k,dp);
            maxSum = max(maxSum,sum);
        }
        return dp[index] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        if(k==arr.size()){
            return *max_element(arr.begin(),arr.end())*k;
        }
        vector<int>dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};