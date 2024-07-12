class StockSpanner {
public:
    stack<pair<int,int>>q;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(q.empty()){
            q.push(make_pair(price,1));
            return 1;
        }
        else{
            int ans =1;
            while(!q.empty() && q.top().first<=price){
                ans+=q.top().second;
                q.pop();
            }
            q.push(make_pair(price,ans));
            return ans;
        }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */