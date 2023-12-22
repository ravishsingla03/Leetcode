class Solution {
public:
    int maxScore(string s) {

        int c1=0;
        int c2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c2++;
            }
            else{
                c1++;
            }
        }
        if(c2==0){
            return c1-1;
        }
        if(c1==0) return c2-1;

        int ans =INT_MIN;
        int c3=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                c3++;
            }
            if(s[i]=='1'){
                c2--;
            }
            ans=max(ans,c3+c2);
        }
        return ans;
    }
};