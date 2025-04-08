class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int maxleft =h[0];
        int maxr = h[n-1];
        int i =0;
        int j = n-1;
        int ans =0;
        while(i<j){
            if(maxleft>maxr){
                int tot = maxr - h[j];
                if(tot>0){
                    ans+=tot;
                }
                j--;
                maxr = max(maxr,h[j]);
            }
            else{
                int tot = maxleft - h[i];
                if(tot>0){
                    ans+=tot;
                }
                i++;
                maxleft = max(maxleft,h[i]);
            }
        }
        return ans;
    }
};