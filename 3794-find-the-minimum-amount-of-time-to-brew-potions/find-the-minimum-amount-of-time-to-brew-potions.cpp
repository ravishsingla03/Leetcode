#define ll long long 
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        ll n = skill.size();
        ll m= mana.size();

        vector<ll>done(n,0);
        for(ll i = 0;i<m;i++){
            ll lastend =0;
            for(ll j =0;j<n;j++){
                ll start = max(lastend,done[j]);

                lastend = done[j] = start + skill[j]*mana[i];
            }
            for(ll j = n-1;j>=1;j--){
                done[j-1] = done[j] - skill[j]*mana[i];
            }
        }

        return done[n-1];
    }
};