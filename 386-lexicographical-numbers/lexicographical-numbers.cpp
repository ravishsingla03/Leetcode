class Solution {
    void solve(int num,int n,vector<int>&ans){
        if(num<=n){
            ans.push_back(num);
        }
        else{
            return;
        }
        for(int i = 0;i<=9;i++){
            solve(num*10 + i,n,ans);
        }
        return ;
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i =1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};