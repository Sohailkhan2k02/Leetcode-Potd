class Solution {
public:
    // APPROACH 1 //
    // int mostBooked(int n, vector<vector<int>>& meetings) {
    //     sort(meetings.begin(),meetings.end());
    //     vector<long long> lastind(n,0);
    //     vector<int> cnt(n,0); // will store the count of how many times the room is used

    //     for(vector<int>& meet : meetings){
    //         int start = meet[0];
    //         int end = meet[1];
    //         int duration = end - start;
    //         bool found = false;

    //         long long roomtime = LLONG_MAX;
    //         int endroom = 0;

    //         for(int i = 0; i < n; i++){
    //             if(lastind[i] <= start){
    //                 found = true;
    //                 lastind[i] = end;
    //                 cnt[i]++;
    //                 break;
    //             }

    //             if(lastind[i] < roomtime){
    //                 roomtime = lastind[i];
    //                 endroom = i;
    //             }
    //         }
            
    //         if(!found){
    //             lastind[endroom] = lastind[endroom] + duration;
    //             cnt[endroom]++;
    //         }
    //     }

    //     int res = -1, maxi = INT_MIN;
    //     for(int i = 0; i < n; i++){
    //         if(cnt[i] > maxi){
    //             maxi = cnt[i];
    //             res = i;
    //         }
    //     }
    //     return res;
    // }

    // APPROACH 2 //

    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings)); //sort by starting time of meetings

        vector<int> roomsUsedCount(n, 0); //Each room is used 0 times in the beginning

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        //To store {earliest room empty time, room No.}
        
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        //To store rooms that are used
        for(int room = 0; room < n; room++) {
            unusedRooms.push(room); //All rooms are unused in the beginning
        }

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];

            //First see, by this time, which rooms can be empty now
            //And move them to unusedRooms
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else { //We don't have any room available now. Pick earliest end room
                int room          = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end-start), room});
                roomsUsedCount[room]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};
