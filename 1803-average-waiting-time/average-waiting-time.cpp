class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int timer = c[0][0];
        double ans =0;
        for(int i = 0;i<c.size();i++){
            int arr = c[i][0];
            if(timer<arr){
                timer =arr;
            }
            int ct = c[i][1];
            if(timer>arr){
                ans+=timer-arr;
            }
            ans+=ct;
            timer +=ct;
        }
        return ans/c.size();
    }
};