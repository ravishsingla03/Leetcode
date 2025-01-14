class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        vector<int>v(n+1,0);
        int count =0;
        for(int i=0;i<n;i++){
            v[A[i]]++;
            if(v[A[i]]==2){
                count++;
            }
            v[B[i]]++;
            if(v[B[i]]==2){
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }

};