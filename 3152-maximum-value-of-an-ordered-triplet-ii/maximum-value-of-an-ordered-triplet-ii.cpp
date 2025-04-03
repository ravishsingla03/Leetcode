class Solution {
public:
    long long maximumTripletValue(vector<int>& arr) {
        vector<int>prefixmax;
        vector<int>suffixmax(arr.size());

        int maxi = arr[0];
        for(int i=0;i<arr.size();i++){
            if(maxi<arr[i]){
                maxi =arr[i];
            }
            prefixmax.push_back(maxi);
        }

        int maxi2=arr[arr.size()-1];
        for(int i=arr.size()-1;i>=0;i--){
            if(maxi2<arr[i]){
                maxi2 =arr[i];
            }
            suffixmax[i]=maxi2;
        }

        for(auto i: prefixmax){
            cout<<i<<" ";
        }
        cout<<endl;

        cout<<endl;
        for(auto i: suffixmax){
            cout<<i<<" ";
        }
        long long ans=0;
        if(arr.size()==3){
            long long temp =1LL * (prefixmax[0]-arr[1])*suffixmax[2];
            ans = max(ans,temp);
        }
        for(int i=1;i<arr.size()-1;i++){
            long long temp = 1LL* (prefixmax[i-1]-arr[i])*suffixmax[i+1];
            ans = max(ans,temp);
        }
        return ans;
    }
};