class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int count=0;
        vector<int>v(201,0);
        for(auto i: nums){
            v[100+i]++;
        }
        int j=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                nums[j++] = i-100;
                count++;
            }
        }
        return count;
    }
};