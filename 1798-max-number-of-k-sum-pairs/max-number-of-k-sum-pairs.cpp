class Solution {
    
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n =nums.size();
        int j=n-1;
        int count=0;
        while(i<j){
            int sum =nums[i]+ nums[j];
            if(sum==k){
                count++;
                i++;
                j--;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};