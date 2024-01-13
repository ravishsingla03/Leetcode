class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(arr[t[i]-'a']>0)
                arr[t[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=arr[i];
        }
        return ans;
    }
};