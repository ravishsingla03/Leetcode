class Solution {
    int solve(int index , vector<vector<int>>&books,int currshelf,int currheight,int givenwidth,vector<vector<int>>&dp){
        if(index==books.size()-1){
            if(books[index][0]<=currshelf){
                return max(currheight,books[index][1]);
            }
            return currheight + books[index][1];
        }

        if(dp[index][currshelf]!=-1){
            return dp[index][currshelf];
        }
        int same = INT_MAX;
        if(books[index][0]<=currshelf){
            same  = solve(index+1,books,currshelf - books[index][0], max(currheight,books[index][1]),givenwidth,dp);
        }
        int next = currheight + solve(index+1,books,givenwidth-books[index][0],books[index][1],givenwidth,dp);
        return dp[index][currshelf] = min(next,same);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf) {
        vector<vector<int>>dp(books.size(),vector<int>(shelf+1,-1));
        return solve(0,books,shelf,0,shelf,dp);
    }
};