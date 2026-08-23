class Solution {
public:
    bool sumGame(string num) 
    {
        int n = num.length();
        double res = 0;
        for (int i = 0; i < n; i++)
        {
            double sign = (i < n / 2) ? 1 : -1;
            double value = (num[i] == '?') ? 4.5 : (num[i] - '0');
            res += sign * value;
        }
        return res != 0.0;
    }
};
