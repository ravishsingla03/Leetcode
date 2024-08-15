class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxi =INT_MIN;
        for(int i=0;i<nums.size();i++){
            double product = nums[i];
            for(int j=i+1;j<nums.size();j++){
                maxi = max(product,maxi);
                product  = product * nums[j];
            }
            maxi = max(product,maxi);
        }
        return maxi;
    }
};