class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = speed.size();
        map<double,double>mp;
        for(int i=0;i<n;i++){
            mp[pos[i]]=speed[i];
        }
        vector<double>fin;
        for(auto i: mp){
            double dis = target -i.first;
            double time = dis/i.second;
            fin.push_back(time);
        }
        for(auto i: fin){
            cout<<i<<" ";
        }
        stack<double>st;
        int count =0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<fin[i]){
                st.pop();
            }
            if(st.empty()){
                count++;
            }
            st.push(fin[i]);
        }
        return count;
    }
};