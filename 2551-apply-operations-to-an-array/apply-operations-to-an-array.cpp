class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int i=0;
        int j =0;
        while(i<n){
            while(i<n && nums[i]!=0){
                i++;
            }
            j=i;
            while(j<n && nums[j]==0){
                j++;
            }
            if(i< n && j< n){
                swap(nums[i],nums[j]);
            }
            i++;
            j++;
        }
        return nums;
    }
};