class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp(i+1,1);
            ans.push_back(temp);
        }
        if(numRows<3){
            return ans;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<ans[i].size()-1;j++){
                cout<<ans[i][j]<<" lund";
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
            cout<<"chut ";
        }
        return ans;
    }
};