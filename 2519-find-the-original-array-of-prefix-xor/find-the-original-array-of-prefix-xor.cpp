class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>v;
        int pr = pref[0];
        v.push_back(pr);
        for(int i=1;i<pref.size();i++){

            pr = pref[i]^pref[i-1];
            v.push_back(pr);
        }
        return v;
    }
};