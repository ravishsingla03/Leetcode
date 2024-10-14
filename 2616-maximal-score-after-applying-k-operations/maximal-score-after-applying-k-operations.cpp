class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto i: nums){
            q.push(i);
        }
        long long ans = 0;
        for(int i=0;i<k;i++){
            ans += q.top();
            double x = q.top();
            q.pop();
            q.push(ceil(x/3));
        }
        return ans;
    }
};