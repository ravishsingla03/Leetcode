class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int n = nums.size();
        int high = nums[n-1] - nums[0];

        while(low<high){
            int mid = (low+high)/2;
            int j=0;
            int count=0;
            // int i =0;
            for(int i=0;i<n;i++){
                while(j<n && nums[j]-nums[i]<=mid){
                    j++;
                }   
                count+= j-i -1;
            }
            // count = (j*(j+1))/2;
            if(count<k){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};