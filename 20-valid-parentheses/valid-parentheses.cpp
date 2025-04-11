class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char temp =s[i];
            if(temp=='(' || temp=='{' || temp=='['){
                st.push(temp);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if(top=='(' && temp !=')'){
                    return false;
                }
                if(top=='{' && temp !='}'){
                    return false;
                }
                if(top=='[' && temp !=']'){
                    return false;
                }
                else{
                    if(!st.empty()){
                        st.pop();
                    }
                }
            }
            
        }
        return st.empty();
    }
};