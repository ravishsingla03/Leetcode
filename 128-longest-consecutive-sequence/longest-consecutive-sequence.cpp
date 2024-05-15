class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int count=1;
        int fans=0;
        vector<int>v;
        for(auto i: mp){
            v.push_back(i.first);
            cout<<i.first<<" ";
        }

        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-v[i]!=1){
                fans = max(count,fans);
                count=1;
            }else{
                count++;
            }
        }
        fans= max(count,fans);
        return fans;
    }
};