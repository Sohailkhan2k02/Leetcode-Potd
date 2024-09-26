//T.C : O(n)
//S.C : O(n)
class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int>mpp;
    bool book(int s, int e) {
        mpp[s]++,mpp[e]--;
        int sum=0;
        for(auto [u,f]:mpp){
            sum+=f;
            if(sum>1){
                mpp[s]--;
                mpp[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
