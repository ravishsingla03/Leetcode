class Solution {
    void removevalid(string s, stack<pair<char,int>>&st){
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else{
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
        }
    }
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        removevalid(s,st);
        vector<int>v;
        v.push_back(s.size());
        while(!st.empty()){
            v.push_back(st.top().second);
            st.pop();
        }
        v.push_back(-1);

        int maxi =INT_MIN;
        for(int i=0;i<v.size()-1;i++){
            cout<<v[i]<<" ";
            maxi = max(maxi ,abs(v[i] - v[i+1]-1));
        }
        return maxi;
    }
};