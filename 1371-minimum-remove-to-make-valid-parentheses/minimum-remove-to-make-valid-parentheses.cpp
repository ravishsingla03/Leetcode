class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        string ans="";
        for(auto i: s){
            if(i==')' && st.empty()){
                continue;
            }
            else if(i==')' && !st.empty()){
                st.pop();
            }
            else if(i=='('){
                st.push(i);
            }
            ans+=i; 
        }

        stack<char>st1;
        string fans="";
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='(' && st1.empty()){
                continue;
            }
            else if(ans[i]=='(' && !st1.empty()){
                st1.pop();
            }
            else if(ans[i]==')'){
                st1.push(ans[i]);
            }
            fans+=ans[i]; 
        }
        // int count=0;
        // while(!st.empty()){
        //     count++;
        //     st.pop();
        // }
        // string fans ="";
        // for(auto i: ans){
        //     if(count>0 && i=='('){
        //         count--;
        //         continue;
        //     }
        //     fans+=i;
        // }
        reverse(fans.begin(),fans.end());
        return fans;
    }
};