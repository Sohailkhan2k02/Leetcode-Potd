class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        string lastArrive=max(arriveAlice,arriveBob);
        string earlyLeave=min(leaveAlice,leaveBob);
        if(earlyLeave<lastArrive) return 0;
        int startMonth=stoi(lastArrive.substr(0,2))-1;
        int endMonth=stoi(earlyLeave.substr(0,2))-1;
        int startDate=stoi(lastArrive.substr(3,2));
        int endDate=stoi(earlyLeave.substr(3,2));
        
        if(startMonth==endMonth) return endDate-startDate+1;
        int totalDays=days[startMonth]-startDate+1;
        for(int i=startMonth+1;i<endMonth;i++){
            totalDays+=days[i];
        }
        totalDays+=endDate;
       return totalDays;
    }
};
