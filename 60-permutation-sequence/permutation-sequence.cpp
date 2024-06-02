class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fact=1;
        for(int i=1;i<=n;i++)
        {
            fact = fact*i;
            v.push_back(i);
        }

        fact= fact/n;
        string ans="";
        k=k-1;
        while(true){
            ans = ans+ to_string(v[k/fact]);
            v.erase(v.begin() + k/fact);
            if(v.empty()){
                break;
            }
            k = k % fact;
            fact = fact/v.size();
        }
        return ans;
    }
};