class MyCalendarTwo {
    map<int,int> map;
public:
    MyCalendarTwo() {
      
    }
    
    bool book(int startTime, int endTime) {
       map[startTime]++;map[endTime]--;
       int prefix=0;
       for(auto it: map){
        prefix+=it.second;
        if(prefix==3){
            map[startTime]--;map[endTime]++;
            return false;

        }
       }
       return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */