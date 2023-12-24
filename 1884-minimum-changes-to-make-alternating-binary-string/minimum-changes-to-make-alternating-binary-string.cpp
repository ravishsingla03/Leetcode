class Solution {
public:
    int minOperations(string s) {
        int count1=0,count2=0;
        if(s[0]=='0'){
            count1=0;
        }
        else{
            count1++;
        }
        if(s[0]=='1'){
            count2=0;
        }
        else{

            count2++;
        }
        for(int i=1;i<s.size();i++){
            if(i%2==0 && s[i]!='0'){
                count1++;
            }
            else if(i%2!=0 && s[i]!='1'){
                count1++;
            }
        }
        for(int i=1;i<s.size();i++){
           if(i%2==0 && s[i]!='1'){
                count2++;
            }
            else if(i%2!=0 && s[i]!='0'){
                count2++;
            }
        }
        return min(count1,count2);
    }
};