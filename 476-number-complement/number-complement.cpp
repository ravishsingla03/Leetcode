class Solution {
public:
    int findComplement(int num) {
        int n =num;
        vector<int>v;
        while(n>0){
            v.push_back(n%2);
            n=n/2;
        }
        int ans =0;
        int j=0;
        for(auto i: v){
            if(i==0){
                ans = ans + pow(2,j);
            }
            j++;
        }
        return ans;
    }
};