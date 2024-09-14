class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto i: nums){
            maxi =max(maxi,i);
        }
        int ans=1;
        int fans =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maxi && nums[i-1]==maxi){
                ans++;
            }
            else{
                ans=1;
            }
            
                fans = max(ans,fans);
            
        }
        return fans;
    }
};