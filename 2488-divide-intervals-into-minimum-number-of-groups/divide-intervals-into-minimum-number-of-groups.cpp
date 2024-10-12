class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        sort(in.begin(),in.end());

        priority_queue<int,vector<int>,greater<int>>q;

        for(int i =0;i<in.size();i++){
            if(q.empty()){
                q.push(in[i][1]);
            }
            else{
                if(q.top()>=in[i][0]){
                    q.push(in[i][1]);
                }
                else{
                    q.pop();
                    q.push(in[i][1]);
                }
            }
        }
        return q.size();
    }
};