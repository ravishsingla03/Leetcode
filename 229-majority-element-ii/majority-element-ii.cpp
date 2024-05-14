class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<size;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>size/3){
                ans.push_back(nums[i]);
                mp[nums[i]]=INT_MIN;
            }
        }
        return ans;
    }
};