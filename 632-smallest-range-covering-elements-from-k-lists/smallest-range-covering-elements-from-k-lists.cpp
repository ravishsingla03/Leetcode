class node{
    public:
    int data;
    int row;
    int col;
    node(int d ,int i , int j){
        data=d;
        row=i;
        col=j;
    }
};
class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini =INT_MAX;
        int maxi = INT_MIN;
        priority_queue<node*,vector<node*>,compare> q;

        for(int i =0;i<nums.size();i++){
            maxi =max(maxi ,nums[i][0]);
            mini =min(mini ,nums[i][0]);
            node* temp =new node(nums[i][0],i,0);
            q.push(temp);
        }    

        int start = mini;
        int end = maxi;
        cout<<start<<' '<<end<<' ';

        while(!q.empty()){
            node* temp2 = q.top();
            q.pop();

            mini =temp2->data;
            if(maxi - mini < end - start){
                start =mini;
                end =maxi;
            }

            if(temp2->col+1 < nums[temp2->row].size()){
                cout<<temp2->row<<' ';
                maxi = max(maxi , nums[temp2->row][temp2->col+1]);
                node* temp3= new node(nums[temp2->row][temp2->col+1],temp2->row,temp2->col+1);
                q.push(temp3);
            }
            else{
                break;
            }
        // cout<<start<<' '<<end<<' ';
        }
        return {start,end};
    }
};