//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& arr, int k) {
        int n=arr.size();
        if(k==n) return arr;
        vector<int>temp(arr),result;
        nth_element(begin(temp),begin(temp)+k-1,end(temp),greater<int>());
        int kthlargest=temp[k-1];
        int countk=count(begin(temp),begin(temp)+k,kthlargest);
        for(auto &num:arr){
            if(num>kthlargest){
                result.emplace_back(num);
            }else if(num==kthlargest && countk>0){
                result.emplace_back(num);
                countk--;
            }
            if(result.size()==k) break;
        }
        return result;
    }
};
