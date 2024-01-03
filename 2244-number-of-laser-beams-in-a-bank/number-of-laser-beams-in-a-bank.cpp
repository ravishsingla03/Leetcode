class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
            int count1 =0;
            int count2 =0;
            for(auto j:bank[0]){
                if(j=='1'){
                    count1++;
                }
            }
        int ans=0;
        for(int i=1;i<bank.size();i++){
            for(auto j:bank[i]){
                if(j=='1'){
                    count2++;
                }
            }
            if(count2!=0){
                ans+=count1*count2;
                count1=count2;
                count2=0;
            }
        }
        return ans;
    }
};