class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int start = 0;
        int end= n-1;
        int mid =start -(start-end)/2;
        
        while(start<end){
            if(nums[mid]>=nums[0]){
                start =mid+1;
            }
            else{
                end =mid;
            }
            mid =start -(start-end)/2;
        }

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target  && nums[n-1]>=target){
            start =mid+1;
            end = n-1;
            mid =start -(start-end)/2;
            while(start<=end){
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target){
                    end =mid-1;
                }
                else{
                    start =mid+1;
                }
                          mid =start -(start-end)/2;
            }
        }
        else{
            start =0;
            end = mid-1;
            mid =start -(start-end)/2;
            while(start<=end){
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target){
                    end =mid-1;
                }
                else{
                    start =mid+1;
                }
                          mid =start -(start-end)/2;
            }
        }
        return -1;
    }
};