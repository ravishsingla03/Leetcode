class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>left=arr;
        vector<int>right=arr;

        int n = arr.size();

        int sum =arr[n-1];
        for(int i=n-2;i>=0;i--){
            sum = sum^arr[i];
            right[i] = sum;
        }

        sum = arr[0];
        for(int i=1;i<n;i++){
            sum = sum^arr[i];
            left[i] = sum;
        }


        for(auto i:queries){
            int x = i[0]-1;
            int y = i[1]+1;
            int temp = sum;
            if(x>=0){
                temp = temp^left[x];
            }
            if(y<n){
                temp = temp ^right[y];
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};