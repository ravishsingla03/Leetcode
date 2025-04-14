class Solution {
    bool ispossible(vector<int>&piles,int h,int mid){
        int n = piles.size();
        for(int i=0;i<n;i++){
            int time = piles[i]/mid + (piles[i]%mid ? 1:0);
            if(h-time<0){
                return false;
            }
            h = h-time;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int low = 1;
        int high = piles[n-1];
        int ans =-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ispossible(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};