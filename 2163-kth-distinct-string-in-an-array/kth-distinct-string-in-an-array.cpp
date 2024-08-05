

class Solution {
    bool static comp(pair<int,string> a ,pair<int,string> b){
        return a.first<b.first;
    }
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,pair<int,int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].first++;
            mp[arr[i]].second=i;
        }



        vector<pair<int,string>>v;

        for(auto i:mp){
            if(i.second.first==1)
            v.push_back({i.second.second,i.first});
        }

        sort(v.begin(),v.end(),comp);

        int count =1;
        for(auto i: v){
            cout<<i.first<<" "<<i.second<<" "<<count<<endl;
            if(count==k){
                return i.second;
            }
            count++;
        }

        return "";
    }
};