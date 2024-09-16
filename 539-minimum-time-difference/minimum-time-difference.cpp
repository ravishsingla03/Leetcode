class Solution {
public:
    int findMinDifference(vector<string>& t) {

        vector<pair<int,int>>v;
        for(auto i:t){
            int x = i[0]-'0';
            x=x*10 + i[1]-'0';

            int y = i[3]-'0';
            y=y*10 + i[4]-'0';
            v.push_back({x,y});
        }

        sort(v.begin(),v.end());

        int mini =INT_MAX;
        for(int i=1;i<v.size();i++){
            int h = (v[i].first - v[i-1].first)*60;
            int m = (v[i].second - v[i-1].second);
            mini = min(mini,h+m);
        }
        int h = ((24 - v[v.size()-1].first) + v[0].first )*60;
        int m = v[0].second - (v[v.size()-1].second) ;
        mini = min(mini , h+m);

        return mini;
    }

};