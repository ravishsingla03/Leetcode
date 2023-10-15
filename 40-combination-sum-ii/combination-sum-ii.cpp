class Solution {
    map<vector<int>, bool> mp;
    void solve(vector<int>&temp , vector<int>&c, int tar,int index){
        if(tar==0){
            if(!mp[temp])
                mp[temp]=true;
        }
        if(tar<0){
            return;
        }
        if(index>c.size()-1){
            return;
        }
        for(int i= index;i<c.size();i++){
            if(c[i]>tar){
                break;
            }
            if(i  > index && c[i] == c[i-1])
                continue;
            temp.push_back(c[i]);
            solve(temp,c,tar - c[i],i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<int> temp;
        solve(temp,c,target,0);
        vector<vector<int>>v;
        for(auto i:mp){
            v.push_back(i.first);
        }
        return v;
    }
};