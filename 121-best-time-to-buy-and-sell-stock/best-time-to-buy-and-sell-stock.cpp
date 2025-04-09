class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int i =0,j=1;
        int ans =0;
        while(j<n){
            int temp = p[j]-p[i];
            ans =max(ans,temp);
            if(p[i]>p[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }

};