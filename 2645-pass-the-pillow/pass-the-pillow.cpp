class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n){
            return time+1;
        }
        else{
            int round = time/(n-1);
            int step = time%(n-1);
            if(round%2==0){
                return step+1;
            }else{
                return n-step;
            }
        }
    }
};