class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
        }
        if(count==0){
            return 0;
        }
        deque<int>q;
        int count1=0;
        for(int i=0;i<count;i++){
            q.push_back(nums[i]);
            if(nums[i]==1){
                count1++;
            }
        }

        int ans = count-count1;

        for(int i=count;i<nums.size();i++){
            int x= q.front();
            q.pop_front();
            if(x==1){
                count1--;
            }
            q.push_back(nums[i]);
            if(nums[i]==1){
                count1++;
            }

            ans =min(ans,count-count1);

            cout<<ans<<" ";
        }

        for(int i=0;i<count-1;i++){
            int x= q.front();
            q.pop_front();
            if(x==1){
                count1--;
            }
            q.push_back(nums[i]);
            if(nums[i]==1){
                count1++;
            }
            ans =min(ans,count-count1);
            cout<<ans<<" ";
        }

        
        return ans;
    }
};