//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int>mpp;
    bool book(int s, int e) {
        mpp[s]++,mpp[e]--;
        int sum=0;
        for(auto [u,f]:mpp){
            sum+=f;
            if(sum>=3){
                mpp[s]--,mpp[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
