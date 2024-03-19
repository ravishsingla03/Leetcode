class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // if(n==1){
        //     return tasks.size();
        // }
        int arr[26]={0};
        for(auto i: tasks){
            arr[i-'A']++;
        }
        sort(begin(arr),end(arr));
        int chunk = arr[25] - 1;
        int idel = chunk * n;

        for(int i=24; i>=0; i--){
            idel -= min(chunk,arr[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};