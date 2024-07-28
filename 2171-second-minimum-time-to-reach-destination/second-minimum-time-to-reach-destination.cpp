class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>>adj;
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<pair<int,int>> timeTaken;
        for(int i=0;i<n+1;i++){
            timeTaken.push_back({INT_MAX,INT_MAX});
        }

        // O(2(V+E))
        // O(V) + 2v + V*E
        queue<pair<int,int>> q;
        timeTaken[1].first = 0; 
        q.push({1,0});
        while(!q.empty()){
            pair<int,int> element = q.front();
            int node = element.first;
            int curTime = element.second;
            q.pop();
            if(node == n){
                if(timeTaken[node].second!=INT_MAX){
                    break;
                }
            }
            //if signal if red, add wait time and keep moving 
            if ((curTime / change) % 2 !=0){
                int waitTime = change - (curTime%change);
                curTime = curTime + waitTime + time;
            }else{ //if signal is green, keep moving
                curTime = curTime + time;
            }
            for(auto neighbour : adj[node]){
                // level - 1: A (6)
                if (timeTaken[neighbour].first == INT_MAX){ //first time visit
                    timeTaken[neighbour].first = curTime;
                    // queue.offer(new int[]{neighbour, curTime});
                    q.push({neighbour,curTime});
                }
                // level - 1: A (6)
                //second time visit but at different level(very important)
                // 3, 6 ,9..
                else if(timeTaken[neighbour].second == INT_MAX && curTime > timeTaken[neighbour].first){ 
                    timeTaken[neighbour].second = curTime;
                    // queue.offer(new int[]{neighbour, curTime});
                    q.push({neighbour,curTime});
                }
            }
        }
        return timeTaken[n].second;
    }
};