class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start =0;
        double temp =0;
        double maxi =INT_MIN;
        for(int i =0;i<k;i++){
            temp +=nums[i];
        }
        maxi = max(maxi,temp/k);
        cout<<maxi;
        for(int i=k;i<nums.size();i++){
            temp+=nums[i];
            temp-=nums[start++];
            maxi = max(maxi,temp/k);
            cout<<maxi<<" ";
        }
        return maxi;
    }
};