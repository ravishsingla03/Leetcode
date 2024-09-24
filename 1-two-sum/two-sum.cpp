class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans=nums;
        sort(nums.begin(),nums.end());
        int i=0;
        int j =nums.size()-1;
        while(i<j){
            int temp =nums[i]+nums[j];
            if(temp==target){
                int x= find(ans.begin(),ans.end(),nums[i]) - ans.begin();
                if(nums[i]==nums[j]){
                    ans.erase(find(ans.begin(),ans.end(),nums[i]));
                }
                int y=find(ans.begin(),ans.end(),nums[j]) - ans.begin();
                if(nums[i]==nums[j]){
                    y++;
                }
                return {x,y};
            }
            else if(temp>target){
                j--;
            }
            else{
                i++;
            }
        }
        return{0,0};
    }
};