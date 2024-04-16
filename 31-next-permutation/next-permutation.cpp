class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //longest prefix match find breakpoint
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        //swap the just greater value
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                reverse(nums.begin()+index+1,nums.end());
                break;
            }
        }
    }
};