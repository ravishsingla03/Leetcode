class Solution {
    void solve(vector<int>& nums,vector<vector<int>>&v,vector<int>temp,int index){
        if(index==nums.size()){
            if(find(v.begin(),v.end(),temp)==v.end()){
                v.push_back(temp);
            }
            return;
        }

        solve(nums,v,temp,index+1);
        temp.push_back(nums[index]);
        solve(nums,v,temp,index+1);
        return ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>v;
        vector<int>temp;
        solve(nums,v,temp,0);
        return v;
    }
};