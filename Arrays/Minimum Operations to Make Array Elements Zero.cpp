class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long operations=0;
    

        for(auto q: queries){
            long long p=log(q[0])/log(4) + 1;
            long long l=pow(4,p);
            long long op=(q[1]-q[0] +1)*p;

            while(q[1]>=l){
                op+=q[1]-l+1;
                l*=4;
            }
            operations+=(op+1)/2;

        }
        return operations;
    }
};
