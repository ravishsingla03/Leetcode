class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count =0;
        while(start>0 && goal>0){
            if(start%2 != goal%2){
                count++;
            }
            start /=2;
            goal /=2;
        }
        while(start>0){
            if(start%2!=0)
                count++;
            start /=2;
        }
        while(goal>0){
            if(goal%2!=0)
                count++;
            goal /=2;
        }
        return count;
    }
};