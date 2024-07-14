class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>arr(52,0);
        for(auto i:s){
            if(isupper(i)){
                arr[i-'A']++;
            }
            else{
                arr[i-'a'+26]++;
            }
        }
        int ans =0;
        int flag=0;
        for(auto &i:arr){
            if(i%2==0 && i!=0){
                ans+=i;
                i=0;
            }
            else if(i%2!=0){
                ans+=(i-1);
                i=1;
                flag=1;
            }
            else if(i!=0){
                flag=1;
            }
        }
        return ans+flag;

    }
};