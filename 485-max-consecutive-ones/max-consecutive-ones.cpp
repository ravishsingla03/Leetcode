class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fans=0;
        int ans =0;
        for(auto i:nums){
            if(i==0){
                fans =max(ans,fans);
                ans=0;
            }
            else{
                ans++;
            }
        }
         fans =max(ans,fans);
        return fans;
    }
};