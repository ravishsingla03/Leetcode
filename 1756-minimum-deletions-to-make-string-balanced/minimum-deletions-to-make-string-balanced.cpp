class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>a(n,0);
        vector<int>b(n,0);

        for(int i=1;i<n;i++){
            a[i]=a[i-1];
            if(s[i-1]=='b'){
                a[i]++;
            }
        }
        for(int i=n-2;i>=0;i--){
            b[i]=b[i+1];
            if(s[i+1]=='a'){
                b[i]++;
            }
        }
        int ans =INT_MAX;
        for(int i=0;i<n;i++){
            ans= min(ans,a[i]+b[i]);
        }
        return ans;
    }
};