class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans(queries.size());
        for(auto i: mp){
            vector<int>q = i.second;
            int size = q.size();
            if(size<=1){
                nums[q[0]]=-1;
                continue;
            }
            for(int index = 0;index<size;index++){
                int temp=INT_MAX;
               if(index==0){
                    int dis =q[0] + n-q[q.size()-1]; 
                    temp = min(temp,dis);
                    temp = min (temp,(q[index+1]-q[index]));
                }
                else if(index==q.size()-1){
                    int dis =  (q[0] + n-q[q.size()-1]);
                    temp = min(temp,dis);
                    temp = min (temp,(q[index]-q[index-1]));
                }
                else{
                    temp = min (temp,(q[index]-q[index-1]));
                    temp = min (temp,(q[index+1]-q[index]));
                }
                nums[q[index]]=temp;
            }
        }

        for(int i =0;i<queries.size();i++){
            ans[i] = nums[queries[i]];
        }
        
        return ans;
    }
};