class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>v;
        unordered_map<string,int>mp;
        unordered_map<string,int>mp1;
        int i =0,j=0;
        
        while(i<s1.size()){
            string temp1="";
            while(s1[i]!=' ' && i<s1.size()){
                temp1+=s1[i];
                i++;
            }
            mp[temp1]++;
            i++;
        }

        while(j<s2.size()){
            string temp1="";
            while(s2[j]!=' ' && j<s2.size()){
                temp1+=s2[j];
                j++;
            }
            mp1[temp1]++;
            j++;
        }

        for(auto i: mp){
            cout<<i.first<<" ";
        }

        for(auto i: mp1){
            cout<<i.first<<" ";
        }
        
        for(auto i: mp){
            if(i.second==1){
                if(mp1.count(i.first)==0){
                    v.push_back(i.first);
                }
            }
        }

        for(auto i: mp1){
            if(i.second==1){
                if(mp.count(i.first)==0){
                    v.push_back(i.first);
                }
            }
        }

        return v;
    }
};