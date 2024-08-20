class Solution {
    int dp[101][201];
    int solve(vector<int>&piles , int index ,int m){
        if(index>=piles.size()){
            return 0;
        }
        if(dp[index][m]!=-1){
            return dp[index][m];
        }
        int ans =INT_MIN;
        int total =0;
        for(int i =0;i<2*m;i++){
            if(i+index<piles.size()) {
                total+= piles[i+index];
            }
            
            ans = max(ans,total - solve(piles,i+index+1,max(m,i+1)));
        }
        return dp[index][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int sum =0;
        for(auto i: piles){
            sum+=i;
        }
        memset(dp,-1,sizeof(dp));
        int diff= solve(piles,0,1);
        return (sum + diff)/2;
    }
};