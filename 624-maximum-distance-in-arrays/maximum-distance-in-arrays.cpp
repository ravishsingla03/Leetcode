class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0][0];
        int maxi = arr[0].back();
        int diff = 0;
        for(int i=1;i<arr.size();i++){
            diff = max(diff , abs(maxi - arr[i][0]));
            diff = max(diff , abs(arr[i].back()- mini));

            maxi = max(maxi,arr[i].back());
            mini = min(mini,arr[i][0]);
        }

        return diff;
    }
};