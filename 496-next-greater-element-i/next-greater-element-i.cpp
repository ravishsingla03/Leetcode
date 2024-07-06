class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        s.push(-1);
        // s.push(num2[nums2.size()-1]);
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.top()<nums2[i]){
                while(s.top()<nums2[i] && s.top()!=-1){
                    s.pop();
                }
            }
            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};