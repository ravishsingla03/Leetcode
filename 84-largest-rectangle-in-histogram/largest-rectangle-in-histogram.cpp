class Solution {
    vector<int>nextsmall(vector<int>h){
        stack<int>st;
        int n = h.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>prevsmall(vector<int>h){
        stack<int>st;
        int n = h.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextsmall(heights);
        vector<int>prev = prevsmall(heights);
        int n = next.size();
        for(auto i: next){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i: prev){
            cout<<i<<" ";
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int temp = heights[i]*(next[i] - prev[i] -1);
            ans = max(ans,temp);
        }
        return ans;
    }
};