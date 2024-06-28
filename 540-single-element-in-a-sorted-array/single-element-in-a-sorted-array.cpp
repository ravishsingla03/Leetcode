class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        
        int start=1;
        int end =nums.size()-2;
        int mid = start - (start-end)/2;
        while(start<=end){
            cout<<mid<<"->"<<nums[mid]<<" ";
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    end = mid-1;
                }
                else{
                    start =mid+1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    end = mid-1;
                }
                else{
                    start =mid+1;
                }
            }
            mid = start - (start- end)/2;
        }
        return -1;
    }
};