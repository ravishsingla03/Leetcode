class Solution {
public:
    int maxArea(vector<int>& h) {
        int i =0;
        int j= h.size()-1;
        int maxi = INT_MIN;
        while(i<j){
            int w = j-i;
            int hi = min(h[j],h[i]);
            maxi  = max(maxi,w*hi);
            if(h[j]<h[i]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};