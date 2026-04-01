class Solution {
public:
    // vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    //     int n=healths.size();
    //     for(int i=0; i<n; i++){
    //         if(directions[i]=='L'){
    //             healths[i]=-healths[i];
    //         }
    //     }
    //     stack<int>st;
    //     for(int i=0; i<n; i++){
    //         while(!st.empty() && st.top()>0 && healths[i]<0){
    //             if(st.top()>abs(healths[i])){
    //                 healths[i]=0;
    //                 int u=abs(st.top());
    //                 st.pop();
    //                 u=u-1;
    //                 st.push(u);
    //             }
    //             else if(st.top()<abs(healths[i])){
    //                 st.pop();
    //                 healths[i]=abs(healths[i]);
    //                 healths[i]-=1;
    //                 // st.push(healths[i]);
    //             }
    //             else{
    //                 st.pop();
    //                 healths[i]=0;
    //             }
    //         }
    //         if(healths[i]!=0){
    //             st.push(healths[i]);
    //         }
    //     }

    //     vector<int>res;
    //     while(!st.empty()){
    //         res.push_back(abs(st.top()));
    //         st.pop();
    //     }
    //     reverse(res.begin(),res.end());
    //     return res;
    // }

    vector<int> survivedRobotsHealths(vector<int>& positions,vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index) {
            indices[index] = index;
        }

        sort(indices.begin(), indices.end(),
             [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices) {
            // Add right-moving robots to the stack
            if (directions[currentIndex] == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    // Pop the top robot from the stack for collision check
                    int topIndex = stack.top();
                    stack.pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        // Current robot survives, top robot is destroyed
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // Both robots are destroyed
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};
