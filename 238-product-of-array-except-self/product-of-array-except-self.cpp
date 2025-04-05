class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>ans;
       ans.push_back(1);
       int prefix =1;
       for(int i=0;i<nums.size()-1;i++){
            prefix*=nums[i];
            ans.push_back(prefix);
       }
       int suffix = 1;
       for(int i= nums.size()-1;i>0;i--){
            suffix=suffix*nums[i];
            ans[i-1] = ans[i-1]*suffix;
       }
       return ans;
    }
};