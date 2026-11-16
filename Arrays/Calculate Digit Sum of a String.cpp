class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k)
        {
            string sdx = "";
            int len = s.size();
            int start = 0;

            while (start < len)
            {
                string digits = s.substr(start, k);
                start += k;
                int sum = 0;

                for (char digit : digits) { sum += digit - '0'; }

                sdx.append(to_string(sum));
            }

            s = sdx;
        }

        return s;
    }
};
