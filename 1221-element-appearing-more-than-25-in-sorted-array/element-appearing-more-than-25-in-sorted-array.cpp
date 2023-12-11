class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size=arr.size()/4;
        int i=0;
        while(i<arr.size()){
            int count=0;
            int x=arr[i];
            while(arr[i]==x &&i<arr.size()){
                count++;
                if(count>size){
                    return arr[i];
                }
                i++;
            }
            count=0;
        }
        return 0;
    }
};