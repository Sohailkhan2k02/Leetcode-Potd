class Solution
{
public:
    using u16 = uint16_t;
    using u32 = uint32_t;

    static u32 triangleNumber(std::vector<int>& nums)
    {
        std::array<u16, 1001> freq{}, prev{}, less{};
        for (int v : nums) ++freq[v & 0xFFFF];

        u16 biggest = freq.size() - 1;
        while (biggest && !freq[biggest]) --biggest;

        // Build inplace linked list in prev array;
        // Store how many values less than x in less[x]
        less[biggest] = (nums.size() & 0xFFFF) - (freq[biggest] + freq[0]);
        for (u16 current = biggest, next = biggest; current--;)
        {
            less[current] = less[next] - freq[current];
            if (freq[current])
            {
                prev[next] = current;
                next = current;
            }
        }

        u32 r = 0;
        for (u16 a = biggest; a != 0; a = prev[a])
        {
            u16 fa = freq[a];
            r += (fa * (fa - 1) * (fa - 2)) / 6;              // a a a
            r += (fa > 1) * ((fa * (fa - 1)) / 2) * less[a];  // a a x
            u32 kb = 0;                                       // a b x
            for (u16 b = prev[a]; b > a / 2; b = prev[b])
            {
                u16 fb = freq[b];
                kb += (fb * (fb - 1)) / 2;               // a b b
                kb += fb * (less[b] - less[a + 1 - b]);  // a b c
            }
            r += kb * fa;
        }

        return r;
    }
};
