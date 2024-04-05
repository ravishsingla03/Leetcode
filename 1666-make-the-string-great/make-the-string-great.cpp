class Solution {
public:
    string makeGood(string s) {
        if(s.size()<2){
            return s;
        }
        string ans="";
        stack<char> st;
        int i=0;
        st.push(s[i]);
        i++;
        while(i<s.size()){
            if(!st.empty() && abs(s[i] - st.top())==32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};