#define ll long long
class Solution {
    ll count(ll x){
        if(x<4){
            return x;
        }
        ll lower = 0;
        for(int i=0;i<20;i++){
            if(x<pow(4,i)){
                lower = i-1;
                break;
            }
        }

        ll left =0;
        for(int i =0;i<lower;i++){
            if(i==0){
                left+=3;
            }
            else{
                ll sum =(1LL * pow(4,i+1) - 1LL * pow(4,i))*(i+1);
                left+=sum;
            }
        }
        ll temp = (x - pow(4,lower) + 1)*(lower+1);
        left+=temp;
        return left;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans= 0;
        for(auto i: queries){
            ll x = i[0];
            ll y = i[1];

            ll  sum = (count(y) - count(x-1));
            ans+=(sum/2);
            if(sum%2!=0){
                ans++;
            }
        }
        return ans;
    }
};