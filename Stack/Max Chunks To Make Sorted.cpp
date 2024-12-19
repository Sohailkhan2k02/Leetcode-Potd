//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int mxx=0,cnt=0;
        for(int i=0; i<n; i++){
            mxx=max(mxx,arr[i]);
            if(mxx==i){
                cnt++;
            }
        }
        return cnt;
    }
};
