class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2){
            return false;
        }

        int mp1[26]={0};
        int mp2[26]={0};

        for(auto i: s1){
            mp1[i-'a']++;
        }

        for(int i=0;i<n1;i++){
            mp2[s2[i]-'a']++;
        }

        int matches=26;
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]){
                matches--;
            }
        }

        if(matches==26){
            return true;
        }
        cout<<matches;
        int j =0;
        for(int i=n1;i<n2;i++){
            mp2[s2[j]-'a']--;
            if(mp1[s2[j]-'a']==mp2[s2[j]-'a']){
                matches++;
            }
            else if (mp1[s2[j]-'a']-1==mp2[s2[j]-'a']){
                matches--;
            }
            j++;
            mp2[s2[i]-'a']++;
            if(mp1[s2[i]-'a']==mp2[s2[i]-'a']){
                matches++;
            }
            else if(mp1[s2[i]-'a']+1==mp2[s2[i]-'a']){
                matches--;
            }
            if(matches==26){
                return true;
            }

        }
        
        return false;
    }
};