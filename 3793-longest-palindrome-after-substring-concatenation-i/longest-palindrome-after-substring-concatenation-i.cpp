class Solution {
    bool palindrome(string s){
        if(s.size()<=1){
            return true;
        }
        int i=0;
        int n = s.size();
        while(i<n/2){
            if(s[i]!=s[n-i-1]){
                return false;
            }
            i++;
        }
        return true;
    }

public:
    int longestPalindrome(string s, string t) {
        vector<string>temp1;
        vector<string>temp2;
        temp1.push_back("");
        temp2.push_back("");
        for(int i=0;i<s.size();i++){
            string a = "";
            a+=s[i];
            temp1.push_back(a);
            for(int j=i+1;j<s.size();j++){
                a+=s[j];
                temp1.push_back(a);
            }
        }
        for(int i=0;i<t.size();i++){
            string a ="";
            a+=t[i];
            temp2.push_back(a);
            for(int j=i+1;j<t.size();j++){
                a+=t[j];
                temp2.push_back(a);
            }
        }

        int ans =0;

        for(auto i: temp1){
            if(palindrome(i)){
                int len = i.size();
                ans=max(ans,len);
            }
        }
        for(auto i: temp2){
            if(palindrome(i)){
                int len = i.size();
                ans=max(ans,len);
            }
        }
        for(int i=0;i<temp1.size();i++){
            for(int j=0;j<temp2.size();j++){
                int len = temp1[i].size()+temp2[j].size();
                if(len>ans && palindrome(temp1[i]+temp2[j])){
                    ans = max(ans,len);
                }
            }
        }
        return ans;
    }
};