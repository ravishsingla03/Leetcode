class Solution {
public:
    int findTheWinner(int n, int k) {
        // if(k==1){
        //     return n;
        // }
        // queue<int>q;
        // int x=1;
        // while(!q.size()==1){

        // }
    int res = 0;
        for (int player_num = 2; player_num <= n; ++player_num) {
            res = (res + k) % player_num;
        }
        return res + 1;

    }
};