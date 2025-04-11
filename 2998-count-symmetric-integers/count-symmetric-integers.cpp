class Solution {
    int solve(int high){
        int count =0;
        int i = 10;
        while(i<=high){
            int temp = i;
            while(i<=high && i<temp*10){
                string s = to_string(i);
                int len = s.size();
                if(len==2 && s[0]==s[1]){
                    count++;
                }
                if(len==4 && (s[0]+s[1])==(s[2]+s[3])){
                    count++;
                }
                i++;
            }
            i = temp*100;
        }
        return count;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        return solve(high) - solve(low-1);
    }
};