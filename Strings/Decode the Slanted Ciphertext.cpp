class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) [[unlikely]] return encodedText;

        const int n = encodedText.length();
        const int cols = n / rows;
        const int skip = cols + 1;

        string res;
        res.resize(n);

        char* __restrict__ dst = res.data();  // __restrict__ = no memory overlap with src, lets compiler skip aliasing checks and optimize harder
        const char* __restrict__ src = encodedText.data();

        int idx = 0;
        for (int startCol = 0; startCol < cols; ++startCol) {
            for (int i = startCol; i < n; i += skip) {
                dst[idx++] = src[i];
            }
        }

        // Trim trailing spaces 
        while (idx > 0 && dst[idx - 1] == ' ') --idx;
        res.resize(idx);

        return res;
    }
};
