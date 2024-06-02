class Solution {
    void solve(vector<int>&c, int target , int index,vector<int>temp , set<vector<int>>&v){

        if(target == 0){
                v.insert(temp);
                return;
        }
        for(int i =index ;i<c.size();i++){
            if(c[i]>target) break;
            if(i>index && c[i]==c[i-1]) continue;


            temp.push_back(c[i]);
            solve(c,target -c[i],i+1,temp,v);
            temp.pop_back();
        }

        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        set<vector<int>>v;
        vector<int>temp;

        solve(c,target , 0,temp,v);   
        vector<vector<int>>ans;
        for(auto i:v){
            ans.push_back(i);
        }
        return ans;
    }
};