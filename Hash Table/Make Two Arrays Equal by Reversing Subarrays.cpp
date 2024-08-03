//APPROACH -1 
//T.C : O(2*n*logn)
//S.C : O(n*n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        map<int,int>m1,m2;
        for(auto i:target) m1[i]++;
        for(auto i:arr) m2[i]++;
        return m1==m2;
    }
};

//APPROACH - 2
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mpp;
        for(auto i:target){
            mpp[i]++;
        }
        int cnt=0;
        for(auto i:arr){
            if(mpp.find(i)!=mpp.end()){
                mpp[i]--;
                if(mpp[i]==0){
                    mpp.erase(i);
                }
            }
            else if(mpp.find(i)==mpp.end()) cnt++;
        }
        return cnt<=0;
    }
};
