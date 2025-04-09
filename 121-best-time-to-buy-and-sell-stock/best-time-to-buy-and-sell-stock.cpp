class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int>suffix(n);
        int suff=0;
        for(int i=n-1;i>=0;i--){
            suff = max(suff,p[i]);
            suffix[i]=suff;
        }
        int ans =0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,suffix[i+1]-p[i]);
        }
        return ans;
    }
};