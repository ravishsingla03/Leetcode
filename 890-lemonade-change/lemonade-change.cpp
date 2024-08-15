class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x=0;
        int y=0;
        for(auto i:bills){
            if(i==5) x++;
            else if(i==10){
                if(x>0){
                    x--;
                    y++;
                }
                else  return false;   
            }
            else{
                if(x>0 && y>0){
                    x--;
                    y--;
                }
                else if(x>2) x= x-3;                
                else return false;
            }
        }
        return true;
    }

};