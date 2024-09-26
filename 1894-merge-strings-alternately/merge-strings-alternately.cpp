class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans="";
        int i =0,j=0;
        while(i<w1.size() &&j<w2.size()){
            ans.push_back(w1[i]);
            ans.push_back(w2[j]);
            i++;
            j++;
        }
        while(i<w1.size()){
            ans.push_back(w1[i]);
            i++;
            
        }
        while(j<w2.size()){

            ans.push_back(w2[j]);
            
            j++;
        }
        return ans;
    }
};