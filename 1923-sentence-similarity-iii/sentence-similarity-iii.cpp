class Solution {
    vector<string>sep(string s1){
        vector<string>v1;
        int i=0;
        string temp ="";
        while(i<s1.size()){
            if(s1[i]==' '){
                if(!temp.empty()){
                    v1.push_back(temp);
                    temp="";
                }
            }
            else{
                temp+=s1[i];
            }
            i++;
        }
        if(!temp.empty()) v1.push_back(temp);
        return v1;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string>v1 = sep(s1);
        vector<string>v2=sep(s2);

        if(v1.size()<v2.size()){
            swap(v1,v2);
        }
        int start =0;
        int end =0;
        int n1 = v1.size();
        int n2 = v2.size();
        while(start<n2 && v1[start]==v2[start]){
            start++;
        }
        while(end<n2 && v1[n1-end-1]==v2[n2-end-1]){
            end++;
        }

        return start+end>=n2;
        
    }
};