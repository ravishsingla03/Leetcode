class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n =temp.size();
        if(n==1){
            return {0};
        }

        vector<int>ans=temp;
        stack<pair<int,int>>s;
        
        s.push({temp[n-1],n});
        ans[n-1]=0;

        for(int i=n-2;i>=0;i--){
            if(s.top().first>=temp[i]){
                if(s.top().first==temp[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({temp[i],i+1});
                    ans[i]=0;
                }
                else{
                    ans[i]=s.top().second - i-1;
                    s.push({temp[i],i+1});
                }
            }
            else{
                while(!s.empty() && s.top().first<=temp[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({temp[i],i+1});
                    ans[i]=0;
                }
                else{
                    ans[i]=s.top().second - i-1;
                    s.push({temp[i],i+1});
                }
            }
        }
        return ans;
    }
};