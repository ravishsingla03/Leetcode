class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long sum =1;
        int count =0;
        int x ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                sum = sum*nums[i];
            }
            else{
                x=i;
                count++;
            }
        }
        vector<int>ans(nums.size(),0);
        if(count>1)
            return ans;
        if(count==1){
            ans[x]=sum;
            return ans;
        }
        cout<<sum;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                ans[i] = sum/nums[i];
            }
            else{
                ans[i] = sum;
            }
        }
        return ans;
    }
};