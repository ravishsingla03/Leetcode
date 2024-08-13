class Solution {
    void solve(int k ,int sum,vector<vector<int>>&ans,vector<int>temp,int index){
        if(sum==0 && temp.size()==k){
            ans.push_back(temp);
        }
        if(temp.size()>k){
            return ;
        }

        for(int i=index;i<=9;i++){
            temp.push_back(i);
            solve(k,sum-i,ans,temp,i+1);
            temp.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        if(n>45){
            return ans;
        }
        vector<int>temp;
        solve(k,n,ans,temp,1);
        return ans;
    }
};