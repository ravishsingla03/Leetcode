class Solution {
    void solve(int index,vector<int>&nums,int &ans,int temp){
        if(index==nums.size()){
            ans+=temp;
            return ;
        }

        solve(index+1,nums,ans,temp^nums[index]);
        solve(index+1,nums,ans,temp);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans =0;
        solve(0,nums,ans,0);
        return ans;
    }
};