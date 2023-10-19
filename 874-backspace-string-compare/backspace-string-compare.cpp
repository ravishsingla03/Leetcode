class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>p,r;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!p.empty())
                    p.pop_back();
            }
            else{
                p.push_back(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!r.empty())
                    r.pop_back();
            }
            else{
                r.push_back(t[i]);
            }
        }
        return p==r;
    }
};