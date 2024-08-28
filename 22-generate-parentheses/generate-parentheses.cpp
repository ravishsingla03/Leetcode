class Solution {
    void solve(vector<string>&ans,int open,int close,int n,string s){
        if(close==n){
            ans.push_back(s);
            return;
        }

        if(close<open){
            solve(ans,open,close+1,n,s+")");
        }
        if (open <n){
            solve(ans,open+1,close,n,s+"(");
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,0,0,n,"");
        return ans;
    }
};