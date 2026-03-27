#define lld long long
#define rep(i,a,n) for(lld i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(lld i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())

#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
#define errorpair(a) cout<<#a<<" = ( "<<((a).first)<<" , "<<((a).second)<<" )\n";


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        auto copy = mat;
        repI(i, 0, n - 1) {
            int shiftDirection = (i & 1) ? 1 : -1;
            int shift = k;
            repI(j, 0, m - 1) {
                int newJ = (j + shiftDirection * shift + m) % m;
                newJ = (newJ + m) % m;
                copy[i][newJ] = mat[i][j];
            }
        }
        return copy == mat;
    }
};
