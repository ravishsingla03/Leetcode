class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans= 0;
        int i=0;
        stack<char>st;
        while(i<s.size()){
                if(s[i]=='('){
                    st.push('(');
                }
                else{
                   if(!st.empty()){
                    st.pop();
                   }
                   else{
                    ans++;
                   }
                }
                i++;
        }
        return ans+st.size();
    }
};