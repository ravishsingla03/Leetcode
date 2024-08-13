class Solution {
    void solve(vector<int>&c , int target, int index, vector<vector<int>>&ans,vector<int>temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index ==c.size()){
            return;
        }

        for(int i= index; i<c.size();i++){
            if(c[i]>target){
                break;
            }
            if(i>index && c[i]==c[i-1]){
                continue;
            }
            temp.push_back(c[i]);
            solve(c,target -c[i],i+1,ans,temp);
            temp.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(c.begin(),c.end());
        solve(c,target,0,ans,temp);
        return ans;
    }
};