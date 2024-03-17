//Approach-1
//T.C : (O(n^2))
//S.C : O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        int i=0; 
        // THE REASON WHY WE HAVENT INTIALISED N AS INTERVAL.SIZE() BECAUSE IF WE INTIALISED AND IF WE ERASE AN INTERVAL THEN THE LOOP WILL BECOME INVALID
        // FOR EG:= IF N=5 AND intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]] AND WE ERASE [3,5] SO N=4 AND HERE LOOP BECOMES INVALID AND WILL THROW ERROR
        // SO FOR CHANGING SIZES WE TAKE i<intervals.size();
        while(i<intervals.size()){
            if(intervals[i][1]<newIntervals[0]){
                i++;
            }
            else if(intervals[i][0]>newIntervals[1]){
                intervals.insert(intervals.begin()+i,newIntervals);
                return intervals;
            }
            else{
                newIntervals[0]=min(intervals[i][0], newIntervals[0]);
                newIntervals[1]=max(intervals[i][1], newIntervals[1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        intervals.push_back(newIntervals);
        return intervals;
    }
};


//Approach-2
//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals){
        int n=intervals.size();
        // HERE WE CAN TAKE N AS i<n BECAUSE WE ARE NOT ERASING ANYTHING IN THE VECTOR WE ARE JUST ADDING IN A VECTOR RES
        vector<vector<int>>res;
        int i=0;
        while(i<n){
            if(intervals[i][1]<newIntervals[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newIntervals[1]){
                break;
            }
            else{
                newIntervals[0]=min(intervals[i][0],newIntervals[0]);
                newIntervals[1]=max(intervals[i][1],newIntervals[1]);
            }
            i++;
        }
        res.push_back(newIntervals);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;   
    }
};
