class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        unordered_map<int,int>a;
        unordered_map<int,int>b;
        for(int i=0;i<n;i++){
            a[A[i]]=1;
            b[B[i]]=1;
            int coun=0;
            for(auto i: a){
                if(b.count(i.first)!=0){
                    coun++;
                }
            }
            ans[i]=coun;

        }
        return ans;
    }

};