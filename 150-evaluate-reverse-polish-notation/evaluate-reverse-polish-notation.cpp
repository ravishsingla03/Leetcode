class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto temp: tokens){
            if(temp=="*"){
                int left = st.top();st.pop();
                int right = st.top();st.pop();
                int res = right*left;
                st.push(res);
            }
            else if(temp=="-"){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();
                int res = right-left;
                st.push(res);
            }
            else if(temp=="+"){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();
                int res = right+left;
                st.push(res);
            }
            else if(temp=="/"){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();
                int res = right/left;
                st.push(res);
            }
            else{
                st.push(stoi(temp));
            }
        }
        return st.top();
    }
};