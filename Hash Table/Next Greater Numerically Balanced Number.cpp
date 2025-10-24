 vector<int> arr = []() {
            vector<int> arr;
            arr.push_back(1);
            arr.push_back(22);

            vector<int> cnt(10);
            int limit = 1000000;

            for (int i = 122; i < limit; i++) {
                string s = to_string(i);
                bool f = false;

                for (char c : s)
                    cnt[c - '0']++;

                for (char c : s) {
                    int d = c - '0';
                    if (cnt[d] != d) {
                        f = true;
                        break;
                    }
                }

                fill(cnt.begin(), cnt.end(), 0); 

                if (!f)
                    arr.push_back(i);
            }

            arr.push_back(1224444); 
            // sort(arr.begin(), arr.end());
            return arr;
        }();

class Solution {
public:
    int nextBeautifulNumber(int n) {
        return *upper_bound(arr.begin(), arr.end(), n);
    }
};
