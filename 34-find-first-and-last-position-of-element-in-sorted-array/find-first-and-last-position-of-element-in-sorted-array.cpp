class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans=-1;
        vector<int>v;
        int low=0;
        int high=nums.size()-1;
        int mid=low + (high-low)/2;
        while (low<=high)
        {
            if (nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if (nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            mid=low + (high-low)/2;
        }
        v.push_back(ans);
        ans=-1;
        low=0;
        high=nums.size()-1;
        mid=low + (high-low)/2;
        while (low<=high)
        {
            if (nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if (nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            mid=low + (high-low)/2;
        }
        v.push_back(ans);
        
        return v;
    }
};
