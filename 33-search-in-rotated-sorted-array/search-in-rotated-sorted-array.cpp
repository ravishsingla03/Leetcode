class Solution {
    int findMin(vector<int>& nums) {
        int x = nums[0];
        int low= 0;
        int high = nums.size()-1;
        int ans =x;
        while(low<high){
            int mid=low +(high-low)/2;
            if(nums[mid]>=x){
                low =mid+1;
            }
            else{
                high =mid;
            }
        }
        if(x<nums[high]){
            return 0;
        }
        return high;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high = nums.size()-1;
        int x= nums[0];
        int mininum = findMin(nums);

        if(target>=nums[mininum] && target<=nums[n-1]){
            low = mininum;
        }
        else{
            high = mininum-1;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return -1;
    }
};