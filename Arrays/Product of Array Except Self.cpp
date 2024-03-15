//Approach-1 (Using Division)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 0;
        int product_without_zero = 1;
        for(int i: nums) {
            if(i == 0)
                product++;
            else
                product_without_zero *= i;
        }
        
        vector<int> result(nums.size());
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                if(product > 0)
                    result[i] = 0;
                else
                    result[i] = product_without_zero/nums[i];
            }
            else {
                if(product > 1)
                    result[i] = 0;
                else
                    result[i] = product_without_zero;
            } 
        }
        return result;
    }
};


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        
        for(int i = n-2; i>=0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        
        vector<int> result(n);
        for(int i = 0; i<n; i++) {
            result[i] = left[i]*right[i];
        }
        
        return result;
    }
};

//Approach-3 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--) {
            result[i] = result[i]*right;
            right *= nums[i];
        }
        
        return result;
    }
};
