class Solution {

    bool issafe(vector<vector<int>>&board , int row ,int col , int n){
        //row

        int x = row;
        int y =col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }

        //diagonal
        y = col;
        while(x>=0 && y>=0){
             if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x= row;
        y = col;
        while(x<n && y>=0){
             if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void addsol(vector<vector<int>>&board , vector<vector<string>>&ans){
        vector<string>temp;
        for(auto i:board){
            string s;
            for(auto j:i){
                if(j==0){
                    s = s+ ".";
                }
                else{
                    s = s+ "Q";
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
        return;
    }
    void solve(vector<vector<int>>&board , int row ,int col , int n,vector<vector<string>>&ans){
        if(col==n){
            addsol(board , ans);
            return ;
        }

        for(int i =0 ;i<n;i++){
            if(issafe(board,i,col,n)){
                board[i][col] = 1;
                solve(board,i,col+1,n,ans);
                board[i][col] = 0;
            }

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<string>>ans;
        solve(board,0,0,n,ans);
        // for(auto i:a){
        //     for( auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};