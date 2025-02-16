class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 2e9;
        while((high - low) > 1e-5){
            double mid  =  high + (low - high)/2;
            double area = 0,total=0;
            for(auto& x: squares){
                total+=  ((double)x[2]*x[2]);
                if(x[1]>=mid){
                    continue;
                }
                else if(x[1]+x[2]<mid){
                    area+= (double)x[2]*x[2];
                }
                else{
                    area+= (double)(mid-x[1])*x[2];
                }
            }

            if(area<total/2){
                low =mid;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};