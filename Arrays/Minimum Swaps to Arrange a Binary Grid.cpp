class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> z;
        for(int i=0;i<grid.size();i++){
            int zeros=0;
            for(int j=n-1;j>=0;j--){
                if(!grid[i][j]) zeros++;
                else break;
            }
            z.push_back(zeros);
        }

        int ans=0;
        int ShouldHave=n-1;

        for(int i=0;i<n;i++){
            int target=-1;
            for(int j=i;j<n;j++){
                if(z[j]>=ShouldHave){
                    target=j;
                    break;
                }
            }

            if (target==-1) return -1;

            for(int j=target;j>i;j--){
                swap(z[j],z[j-1]);
                ans++;
            }

            ShouldHave--;
        }

        return ans;
    }
};
