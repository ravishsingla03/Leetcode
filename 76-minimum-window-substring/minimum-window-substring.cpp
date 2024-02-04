class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        int count=0;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            count++;
        }

        int windowsize =INT_MAX;
        int i=0;
        int j=0;
        int start=0;

        while(j<s.size()){
            char ch =s[j];
            if(mp[ch]>0){
                count--;
            }
            mp[ch]--;

            while(count==0){
                int currsize = j-i+1;
                if(windowsize>currsize){
                    windowsize = currsize;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }

        return windowsize == INT_MAX ? "" : s.substr(start,windowsize);
    }
};