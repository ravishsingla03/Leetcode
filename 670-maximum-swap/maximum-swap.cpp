class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        int maxi = num;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }

        reverse(v.begin(),v.end());
        for(int i =0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                swap(v[i],v[j]);
                int x = 0;
                for(auto i: v){
                    x = x*10 + i;
                }
                maxi = max(x,maxi);
                swap(v[i],v[j]);
            }
        }
        
        return maxi;
    }
};