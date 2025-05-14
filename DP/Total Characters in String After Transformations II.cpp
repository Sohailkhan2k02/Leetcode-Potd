class Solution {
public:
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B, int mod) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; ++j)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        return C;
    }

    Matrix matrixExpo(Matrix A, int power, int mod) {
        int n = A.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            result[i][i] = 1;

        while (power > 0) {
            if (power & 1)
                result = multiply(result, A, mod);
            A = multiply(A, A, mod);
            power >>= 1;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int m = 1e9 + 7;

        // Step 1: Build transformation matrix
        vector<vector<long long>> matrix(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                matrix[i][(i + j) % 26]++;
            }
        }

        // Step 2: Count initial frequencies
        vector<long long> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Step 3: Exponentiate the matrix
        Matrix powered = matrixExpo(matrix, t, m);

        // Step 4: Multiply powered matrix with freq vector
        vector<long long> finalFreq(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                finalFreq[i] = (finalFreq[i] + powered[j][i] * freq[j] % m) % m;

        // Step 5: Sum all frequencies
        long long total = 0;
        for (int i = 0; i < 26; ++i)
            total = (total + finalFreq[i]) % m;

        return total;
    }
};
