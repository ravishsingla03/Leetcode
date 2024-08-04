class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        //  int arr[n * (n + 1) / 2];
        // for (int i = 0, k = 0; i < n; ++i) {
        //     int s = 0;
        //     for (int j = i; j < n; ++j) {
        //         s += nums[j];
        //         arr[k++] = s;
        //     }
        // }
        // sort(arr, arr + n * (n + 1) / 2);
        // int ans = 0;
        // const int mod = 1e9 + 7;
        // for (int i = left - 1; i < right; ++i) {
        //     ans = (ans + arr[i]) % mod;
        // }
        // return ans;
        vector<int>v;

        for(int i=0;i<n;i++){
            int x= nums[i];
            v.push_back(x);
            for(int j=i+1;j<n;j++){
                x+=nums[j];
                v.push_back(x);
            }
        }

        sort(v.begin(),v.end());
        long long int ans=0;
        const int mod = 1e9 + 7;
        for(int i =left-1;i<right;i++){
            ans= (ans%mod + v[i]%mod)%mod;
        }
        return ans;
    }
};