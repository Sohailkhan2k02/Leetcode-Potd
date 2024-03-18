//Approach-1 (Just like Leetcode - "Non Overlapping Intervals")
//Sorting on the basis of "End coordinate"
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        int count         = 1;
        int lastEndPoint  = points[0][1];
        
        for(int i = 1; i<n; i++) {
            int curr_startPoint = points[i][0];
            
            if(curr_startPoint > lastEndPoint) {
                count++;
                lastEndPoint = points[i][1];
            }
        }
        
        return count;
    }
};


//Approach-2 (Sorting on the basis of start coordinate)
//Using O(n) space
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        vector<vector<int>> balloons;
        balloons.push_back(points[0]);
        
        for(int i = 1; i<n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint   = points[i][1];
            
            int prevStartPoint = balloons.back()[0];
            int prevEndPoint   = balloons.back()[1];
            
            if(currStartPoint > prevEndPoint) { //no overlap
                balloons.push_back(points[i]);
            } else {
                //overlap
                balloons.back()[0] = max(prevStartPoint, currStartPoint);
                balloons.back()[1] = min(prevEndPoint, currEndPoint);
            }
        }
        
        return balloons.size();
    }
};
