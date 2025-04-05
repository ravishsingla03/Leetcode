class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n =board.size();
        //rowcheck
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){

                mp[board[i][j]]++;
                if(mp[board[i][j]]>1){
                    return false;
                }
                }
            }
        }
        //col check
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<n;j++){
                if(board[j][i]!='.'){
                mp[board[j][i]]++;
                if(mp[board[j][i]]>1){
                    return false;
                }
                }
            }
        }
        //box check
        unordered_map<int,unordered_map<char,int> >mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    mp[(i/3)*3+(j/3)][board[i][j]]++;
                    if(mp[(i/3)*3+(j/3)][board[i][j]]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};