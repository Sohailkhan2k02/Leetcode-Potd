class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        vector<int> widths;
        gaps.push_back(startTime[0]);
        widths.push_back(endTime[0] - startTime[0]);
        for(int i = 1; i < n; i++){
            gaps.push_back(startTime[i] - endTime[i-1]);
            widths.push_back(endTime[i] - startTime[i]);
        }
        gaps.push_back(eventTime - endTime.back());

        vector<int> lMax(gaps.size()), rMax(gaps.size());
        lMax[0]  = gaps[0];
        rMax[gaps.size()-1] = gaps.back();

        int ans = 0;
        for(int i = 1; i < gaps.size(); i++){
            lMax[i] = max(gaps[i], lMax[i-1]);
            ans = max(ans, gaps[i] + gaps[i-1]);
        }
        ans = max(ans, lMax.back());

        for(int i = gaps.size()-2; i >= 0; i--){
            rMax[i] = max(rMax[i+1], gaps[i]);
        }
        for(int i = 0; i < widths.size(); i++){
            int l = ((i == 0) ? 0 : lMax[i-1]);
            int r = ((i == widths.size()-1) ? 0 : rMax[i+2]);

            int maxi = max(l, r);
            if(maxi >= widths[i]){
                ans = max(ans, widths[i] + gaps[i] + gaps[i+1]);
            }
        }
        // for(auto &val : gaps)cout<<val<<" ";cout<<endl;
        // for(auto &val : widths)cout<<val<<" ";cout<<endl;
        return ans;
    }
};
