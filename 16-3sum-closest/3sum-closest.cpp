class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mindiff= INT_MAX;
        int n= nums.size();
        int anssum = nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum  = nums[i]+ nums[left] + nums[right];
                if(sum==target){
                    return target;
                }
                else if( sum<target){
                    left++;
                }
                else{
                    right--;
                }
                if(abs(sum - target)<mindiff){
                    anssum = sum;
                    mindiff  = abs(sum - target);
                }
            }
        }
        return anssum;
    }
};