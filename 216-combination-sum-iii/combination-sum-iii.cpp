class Solution {
    vector<vector<int>> v;
    void solve(vector<int>temp,int index,int n,int k){
        if(k==0 && n==0){
            v.push_back(temp);
            return;
        }
        if(k==0 || n<0){
            return;
        }
        for(int i=index+1;i<=9;i++){
            temp.push_back(i);

            // cout<<n<<" "<<k<<" "<<i<< " ";
            solve(temp,i,n-i,k-1);
            temp.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int index=0;
        solve(temp,index,n,k);
        return v;
    }
};