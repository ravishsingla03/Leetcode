class Solution {
    // my answer TLE at 143 case
    long long solve(vector<vector<int>>&points,int i,int j,vector<vector<int>>&dp){
        if(i==points.size()){
            return 0;
        }
        if(j==points[0].size()){
            return -1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        long long  ans =-1e9;
        int n = points[0].size();

        for(int col = 0;col<n;col++){
            long long x = solve(points,i+1,col,dp) + points[i][col];
            if(i!=0){
                x-= abs(j-col);
            }
            ans = max(ans ,x);
        }
        return dp[i][j] = ans;
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        // vector<vector<int>>dp(points.size(),vector<int>(points[0].size(),-1));
        // return solve(points,0,0,dp);


         int n=points.size();
        int m=points[0].size();

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));

        for(int i=0;i<m;i++){
            dp[0][i]=points[0][i];
        }

        for(int i=1;i<n;i++){

            vector<long long>left(m),right(m);
            
            left[0]=dp[i-1][0];

            for(int j=1;j<m;j++){
             left[j]=max(left[j-1]-1,dp[i-1][j]);
            }

            right[m-1]=dp[i-1][m-1];

            for(int j=m-2;j>=0;j--){
             right[j]=max(right[j+1]-1,dp[i-1][j]);
            }

            for(int j=0;j<m;j++){
                dp[i][j]=points[i][j]+max(left[j],right[j]);
            }
            
        }

        long long ans=INT_MIN;

        for(int i=0;i<m;i++){
            ans=max(ans,dp[n-1][i]);
        }

        return ans;
    }
};