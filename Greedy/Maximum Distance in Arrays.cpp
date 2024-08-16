//T.C : O(m) where m is the total number of elements in the 2D vector arr.
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n=arr.size();
        int m1=INT_MIN,m2=INT_MAX,i1=-1,i2=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<arr[i].size(); j++){
                if(arr[i][j]>m1){
                    m1=arr[i][j];
                    i1=i;
                }
                if(arr[i][j]<m2){
                    m2=arr[i][j];
                    i2=i;
                }
            }
        }
        int m3=INT_MAX,m4=INT_MIN;
        for(int i=0; i<n; i++){
            if(i1==i) continue;
            for(int j=0; j<arr[i].size(); j++){
                if(arr[i][j]<m3){
                    m3=arr[i][j];
                }
            }
            if(i2==i) continue;
            for(int j=0; j<arr[i].size(); j++){
                if(arr[i][j]>m4){
                    m4=arr[i][j];
                }
            }
        }
        // cout<<i1<<"->";
        // cout<<"maxi -> "<<m1<<" mini ->"<<m3<<" ";
        // cout<<"\n";
        // cout<<i2<<"->";
        // cout<<"mini -> "<<m2<<" maxi ->"<<m4<<" ";
        // cout<<"\n";
        if(m1==INT_MIN || m3==INT_MAX){
            return abs(m2-m4);
        }
        else if(m2==INT_MAX || m4==INT_MIN){
            return abs(m1-m3);
        }
        else return max(abs(m1-m3),abs(m2-m4));
    }
};
