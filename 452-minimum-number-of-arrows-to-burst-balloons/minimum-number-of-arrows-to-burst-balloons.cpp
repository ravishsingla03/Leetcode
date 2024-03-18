class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1;
        pair<int,int> both={points[0][0],points[0][1]};
        for(int i=1;i<points.size();i++){
            if(both.second>=points[i][0]){
                both={points[i][0], min(both.second,points[i][1])};
            }
            else{
                count++;
                both.first=points[i][0];
                both.second=points[i][1];
            }
        }
        return count;
    }
};