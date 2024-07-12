class Solution {
    vector<int> nextsmaller(vector<int>&heights,int n){
        stack<int>s;
        vector<int>next=heights;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                next[i]=n;
            }
            else{
                next[i]=s.top();
            }
            s.push(i);
        }
        return next;
    }
    vector<int> prevsmaller(vector<int>&heights,int n){
        stack<int>s;
        vector<int>prev=heights;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=s.top();
            }
            s.push(i);
        }
        return prev;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n= heights.size();
        vector<int>prev = prevsmaller(heights,n);
        vector<int>next = nextsmaller(heights,n);

        for(int i=0;i<n;i++){
            int b  = next[i]-prev[i]-1;
            maxi  = max(maxi,heights[i]*b);
        }
        return maxi;
    }
};