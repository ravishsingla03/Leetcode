class Solution {
    int kmp(string s ,string rev){
        string newst = s + "#" + rev;

        vector<int>lps(newst.size(),0);
        int pre = 0;
        int suff= 1;
        while(suff<newst.size()){
            if(newst[pre]==newst[suff]){
                lps[suff] = pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps.back();
    }
public:
    string shortestPalindrome(string s) {
        string rev = string(s.rbegin(),s.rend());
        int n  = s.size();
       int count = kmp(s,rev);
       return rev.substr(0,n-count) + s;
    }
};