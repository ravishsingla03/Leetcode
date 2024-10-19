class Solution {
    string solve(int n){
        if(n==1){
            return "0";
        }

        string s = solve(n-1);
        string inv=s;

        for(auto &i: inv){
            if(i=='0'){
                i='1';
            }else{
                i='0';
            }
        }
        reverse(inv.begin(),inv.end());
        return s + "1" + inv;
    }
public:
    char findKthBit(int n, int k) {
        string s = solve(n);
        return s[k-1];
    }
};