class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2){
            return false;
        }

        int mp1[26]={0};
        for(auto i: s1){
            mp1[i-'a']++;
        }

        int mp2[26]={0};
        for(int i=0;i<n1;i++){
            mp2[s2[i]-'a']++;
        }
        int flag=1;
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]){
                flag=0;
            }
        }

        if(flag){
            return flag;
        }
        int j =0;
        for(int i=n1;i<n2;i++){
            mp2[s2[j]-'a']--;
            j++;
            mp2[s2[i]-'a']++;
            int flag=1;
            for(int k=0;k<26;k++){
                if(mp1[k]!=mp2[k]){
                   flag=0;
                }
            }
            if(flag){
                return flag;
            }
        }
        
        return false;
    }
};