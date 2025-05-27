class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int count =0;
        int i=0;
        int j=0;
        int n = nums.size();
        int x = k;
        while(i<n && j<n){
            while(j< n && (nums[j]==1 || x>0 )){
                if(nums[j]==0){
                    nums[j]=2;
                    x--;
                }
                j++;
            }
            ans = max(ans,j-i);
            cout<<ans<<endl;
            while(i< n && nums[i]==1){
                i++;
            }
            x++;
            i++;
        }   
        return ans;
    }
};