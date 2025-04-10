class Solution {
public:
    string minWindow(string s, string t) {
    
        int n1= s.size();
        int n2 = t.size();
        if(n2>n1){
            return "";
        }
        unordered_map<char,int>mp;
        for(int i=0;i<n2;i++){
            mp[t[i]]++;
        }

        int l =0,r=0,minlen = INT_MAX,count=0;
        int start =0;
        while(r<n1){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;
            while(count==n2){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    start =l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
    }
};