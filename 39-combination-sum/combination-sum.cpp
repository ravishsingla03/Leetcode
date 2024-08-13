class Solution {
    void solve(vector<int>&c,int target,int index,vector<vector<int>>&ans,vector<int>temp){
        
        if(index==c.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return ;
        }

        if(c[index]<=target){
            temp.push_back(c[index]);
            solve(c,target-c[index],index,ans,temp);
            temp.pop_back();
        }

        solve(c,target,index+1,ans,temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(c,target,0,ans,temp);
        return ans;
    }
};