class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        int count0=0;
        int count1=0;
        for(auto i:students){
            if(i==0){
                count0++;
            }
            else{
                count1++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==1 && count1>0){
                count1--;
            }
            else if(s[i]==0 && count0>0){
                count0--;
            }
            else{
                return s.size()-i;
            }
        }
        return 0;
    }
};