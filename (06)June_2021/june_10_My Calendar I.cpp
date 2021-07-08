class MyCalendar {
public:
    list<pair<int,int>> l;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto it:l)
        {
            if(max(start,it.first)<min(end,it.second))
                return false;
        }
        l.push_back({start,end});
            return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */