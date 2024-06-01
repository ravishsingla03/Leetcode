class Solution {
    void solve(vector<int>&c,int target,int index,int sum,vector<vector<int>>&v,vector<int>temp){
        if(target == sum){
            v.push_back(temp);
            return ;
        }
        if(index >= c.size()){
            return ;
        }
        if(target<sum){
            return ;
        }


        cout<<sum<<" ";

        for(int i =index ; i<c.size();i++){
            temp.push_back(c[i]);
            solve(c,target,i,sum + c[i],v,temp);
            temp.pop_back();
        }

        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>v;
        vector<int>temp;

        solve(c,target , 0 ,0 ,v , temp);
        return v;
    }
};