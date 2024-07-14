class Solution {
public:
    string countOfAtoms(string f) {
        stack<pair<string,int>>st;
        int i,j,k;
        int n= f.size();

        for(int i=0;i<f.size();i++){
            char ch = f[i];
            if(isupper(ch)){
                //to extract the elment name
                string s ="";
                s+=ch;
                for(j=i+1;j<n;j++){
                    ch = f[j];
                    if(!islower(ch)){
                        break;
                    }
                    s+=ch;
                }

                //to extract the number 

                string digi = "";
                for(k=j;k<n;k++){
                    ch =f[k];
                    if(!isdigit(ch)){
                        break;
                    }
                    digi+=ch;
                }
                if(digi==""){
                    digi="1";
                }
                int digit = stoi(digi);

                st.push({s,digit});
                i =k-1;
            }
            else if(ch=='('){
                st.push({"(",-1});
            }
            else if(ch ==')'){
                //now iterate the digit after the bracket
                string digi = "";
                for(j=i+1;j<n;j++){
                    ch =f[j];
                    if(!isdigit(ch)){
                        break;
                    }
                    digi+=ch;
                }
                if(digi==""){
                    digi="1";
                }
                int digit = stoi(digi);

                //now removign elemtn from stack till open brak
                vector<pair<string,int>> temp;
                pair<string,int> op_pair ={"(",-1};

                while(st.top()!=op_pair){
                    temp.push_back({st.top().first ,st.top().second*digit});
                    st.pop();
                }
                st.pop();
                //putting back in stack
                while(temp.size()>0){
                    st.push(temp.back());
                    temp.pop_back();
                }
                i=j-1;
            }
        }
        // while(!st.empty()){
        //     cout<<st.top().first<<"->"<<st.top().second;
        //     st.pop();
        // }
        map<string,int>mp;
        while(!st.empty()){
            mp[st.top().first]+=st.top().second;
            st.pop();
        }
        string ans ="";

        for(auto p: mp){
            string elem = p.first;
            string sdi = to_string(p.second);
            if(sdi=="1"){
                sdi = "";

            }
            ans+=elem + sdi;
        }
        return ans;
    }
};