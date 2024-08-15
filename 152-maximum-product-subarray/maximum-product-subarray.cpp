class Solution {
    // long long int solve(vector<int>&nums,int index){
    //     if(index==nums.size()){
    //         return 1;
    //     }
    //     long long int maxi =INT_MIN;
    //     for(int i= index; i<nums.size();i++){
    //         maxi = max(nums[i]*solve(nums,i+1),maxi);
    //     }
    //     return maxi;
    // }
public:
    int maxProduct(vector<int>& nums) {
        double maxi = INT_MIN;
        double prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
            prod=1;
        }
        prod =1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};