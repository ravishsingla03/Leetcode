class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        int arr1[26]={0};
        for(auto i: s){
            arr[i-'a']++;
        }

        for(auto i: t){
            arr1[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=arr1[i]){
                return false;
            }
        }
        return 1;
    }
};