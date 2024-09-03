class Solution {
public:
    int getLucky(string s, int k) {
        string number ="";
        for(auto i: s){
           number+= to_string(i-'a'+1);
        }
        cout<<number<<" ";

        int ans =0;
        for(auto i: number){
            ans+=i-'0';
        }

        k--;
        if(k==0){
            return ans;
        }

        while(k--){
            int finala=0;
            while(ans>0){
                finala+=ans%10;
                ans/=10;
            }
            ans = finala;
        }
        // while(k--){
        //     ans=0;
        //     while(number>0){
        //         ans += number%10;
        //         number/=10;
        //     }
        //     number = ans;
        // }
        return ans;
    }
};