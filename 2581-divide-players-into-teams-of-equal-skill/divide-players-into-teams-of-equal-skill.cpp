class Solution {
public:
    long long dividePlayers(vector<int>& sk) {
        sort(sk.begin(),sk.end());
        int n=sk.size();
        int i=1,j=n-2;
        int sum =sk[0]+sk[n-1];
        long long ans=sk[0]*sk[n-1];
        while(i<j){
            if(sum != sk[i]+sk[j]){
                return -1;
            }
            ans+=sk[i]*sk[j];
            i++;
            j--;
        }
        return ans;
    }
};