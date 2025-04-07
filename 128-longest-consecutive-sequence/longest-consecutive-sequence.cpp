class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        int count=1;
        int ans =0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1){
                count++;
            }
            else if(nums[i+1]==nums[i]){
                count =count;
            }
            else{
                ans = max(count,ans);
                count=1;
            }
        }
        ans = max(count,ans);
        return ans;
    }
};