class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        bool flag =false;
        int i=0;
        while(i<nums.size()){
            if(abs(nums[i]-nums[i+1])>k || abs(nums[i+1]-nums[i+2])>k || abs(nums[i]-nums[i+2])>k){
                flag=true;
            }
            if(flag){
                return {};
            }
            else{
                v.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            i+=3;
        }
        return v;
    }
};