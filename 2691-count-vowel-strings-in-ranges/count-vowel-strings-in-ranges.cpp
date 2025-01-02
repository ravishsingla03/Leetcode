class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n =words.size();
        unordered_map<char,bool>mp={{'a',true},{'e',true},{'i',true},{'u',true},{'o',true}};
        vector<int>v1(n,0);
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(mp.count(words[i][0])!=0 && mp.count(words[i][words[i].size()-1])){
                v1[i]++;
            }
            if(i>0){
                v1[i]+=v1[i-1];
            }
        }
        for(auto i:queries){
            if(i[0]==i[1]){
                int x =i[0];
                if(mp.count(words[x][0]) && mp.count(words[x][words[x].size()-1])){
                    v2.push_back(1);
                }
                else{
                    v2.push_back(0);
                }
            }
            else if(i[0]==0){
                v2.push_back(v1[i[1]]);
            }
            else{
                  v2.push_back(v1[i[1]] - v1[i[0]-1]);
            }
        }
        for(auto i : v1){
            cout<<i<<" ";
        }
        return v2;
    }
};