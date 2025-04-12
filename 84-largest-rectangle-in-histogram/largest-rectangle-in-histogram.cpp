class Solution {

public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int ans =0;
        stack<pair<int,int>>st;
        st.push({h[0],0});

        for(int i=0;i<n;i++){
            pair<int,int>temp={h[i],i};
            while(!st.empty() && st.top().first>h[i]){
                temp.second = st.top().second;
                int area = (i-st.top().second)*st.top().first;
                ans = max(ans,area);
                st.pop();
            }
            st.push(temp);
        }
        while(!st.empty()){
             int area = (n-st.top().second)*st.top().first;
                ans = max(ans,area);
                st.pop();
        }

        return ans;
    }
};