class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int j=1;
        int p=n/7;
        for(int i=0;i<=p;i++){
            for(int k=j;k<=j+6 && n>0 ;k++){
                cout<<k<<" ";
                ans+=k;
                n--;
            }
            j++;
        }
        return ans;
    }
};