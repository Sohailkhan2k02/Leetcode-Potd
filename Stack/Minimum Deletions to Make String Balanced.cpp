//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        int count = 0;

        stack<char> st;

        for(int i = 0; i < n; i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }

        return count;
    }
};


//Approach-2 (3 Pass + O(2*n) space)
//T.C : O(3*n)
//S.C : O(2*n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        
        vector<int> left_b(n, 0);
        vector<int> right_a(n, 0);

        int countb = 0;
        for(int i = 0; i < n; i++) {
            left_b[i] = countb;
            if(s[i] == 'b')
                countb++;
        }

        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            right_a[i] = counta;
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        for(int i = 0; i < n; i++) {
            count = min(count, left_b[i] + right_a[i]);
        }

        return count;
    }
};


//Approach-3 (2 Pass + O(n) space)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        
        vector<int> right_a(n, 0);

        
        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            right_a[i] = counta;
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            count = min(count, countb + right_a[i]);
            if(s[i] == 'b')
                countb++;
        }

        return count;



    }
};


//Approach-4 (Constant space)
//T.C : O(2*n)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();

        
        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                counta--;
            count = min(count, countb + counta);

            if(s[i] == 'b')
                countb++;
        }

        return count;
    }
};
