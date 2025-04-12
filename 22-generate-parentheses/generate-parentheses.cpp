class Solution {
public:
    void solve(int i,int j,vector<string>&ans,string temp){

        if(i==j && i==0){
            ans.push_back(temp);
            return ;
        }
        if(i>=0){
            solve(i-1,j,ans,temp+"(");
        }
        if(j>i){
            solve(i,j-1,ans,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,n,ans,"");
        return ans;
    }
};