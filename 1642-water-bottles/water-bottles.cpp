class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        if(numE>numB){
            return numB;
        }
        int ans = numB;
        while(numB>0 && numE<=numB){
            ans += numB/numE;
            numB = numB/numE + numB%numE;
        }
        return ans;
    }
};