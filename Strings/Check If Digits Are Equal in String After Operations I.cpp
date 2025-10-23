class Solution
{
public:
    bool hasSameDigits(std::string& s)
    {
        for (size_t o = s.size(); o > 2;)
        {
            size_t l = o;
            o = 0;
            for (size_t i = 1; i != l; ++i)
            {
                int sum = s[i] + s[i - 1] - 2 * '0';
                s[o++] = static_cast<char>('0' + sum % 10);
            }
        }
        return s[0] == s[1];
    }
};
