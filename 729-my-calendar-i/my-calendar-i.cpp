class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(st.empty()){
            st.insert({start,end});
            return true;
        }
        else{
            for(auto i: st){
                if(i.second>start && i.first<end){
                    return false;
                }
            }
            st.insert({start,end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */