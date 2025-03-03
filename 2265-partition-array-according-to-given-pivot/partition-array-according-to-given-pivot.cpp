class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count =0;
        int count1 =0;
        for(auto i: nums){
            if(i<pivot){
                count++;
            }
            else if(i>pivot){
                count1++;
            }
        }
        int n =nums.size();
        vector<int>ans(n,pivot);
        

        for(int i =n-1;i>=0;i--){
            if(nums[i]<pivot && count>=0){
                ans[count-1] = nums[i];
                count--;
            }
        }
        for(int i =0;i<n;i++){
            if(nums[i]>pivot && count1>=0){
                ans[n-count1] = nums[i];
                count1--;
            }
        }
        return ans;
    }
};