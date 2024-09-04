class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        int x = 0;
        int y= 0;

        int maxi = INT_MIN;
        int arr1[] ={0,1,0,-1};
        int arr2[] ={1,0,-1,0};

        map<pair<int,int>,bool>mp;
        for(auto i: obs){
            mp[{i[0],i[1]}] =true;
        }

        int direc = 0;
        for(auto i: commands){
            if(i>0){
                for(int k =0;k<i;k++){
                    if(mp[{x+arr1[direc] , y + arr2[direc]}]){
                        break;
                    }
                    x = x + arr1[direc];
                    y = y + arr2[direc];
                }
                int dis = pow(x,2) + pow(y,2);
                maxi = max(maxi,dis);
            }
            else if (i==-1){
                direc = (direc + 1)%4;
            }
            else{
                direc = (direc+3)%4;
            }
        }
        return maxi;
    }
};