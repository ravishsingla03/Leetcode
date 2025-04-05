class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int zero =0;
        for(auto i: nums){
            if(i!=0){
                mul*=i;
            }
            else{
                zero++;
            }
        }
        if(zero==1){
            for(auto &i: nums){
                if(i!=0){
                    i=0;
                }
                else{
                    i = mul;
                }
            }
            return nums;
        }
        else if(zero>1){
            vector<int>ans(nums.size(),0);
            return ans;
        }
        else{
            for(auto &i: nums){
                i =mul/i;
            }
            return nums;
        }
    }
};