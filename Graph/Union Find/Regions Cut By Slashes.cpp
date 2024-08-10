//T.C : O(n*m)
//S.C : O(n)
class Solution {

    vector<int> parent;

    int getParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = getParent(parent[node]);
    }

    void unionSet(int a, int b) {
        int parentA = getParent(a);
        int parentB = getParent(b);

        if(parentA == parentB) {
            return;
        }

        parent[parentB] = parentA;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        if(n == 0) {
            return 0;
        }
        int m = grid[0].size();
        parent = vector<int>((n+1)*(m+1)+1);
        for(int i=0; i<parent.size(); i++) {
            parent[i] = i;
        }

        
        for(int i=0; i<n; i++) {
            int a = i*(m+1);
            int b = (i+1)*(m+1);
            unionSet(a, b);

            a = i*(m+1) + m;
            b = (i+1)*(m+1) + m;
            unionSet(a, b);
        }

        for(int j=0; j<m; j++) {
            int a = j;
            int b = j+1;
            unionSet(a, b);

            a = (n)*(m+1) + j;
            b = (n)*(m+1) + j + 1;
            unionSet(a, b);
        }    

        int cnt = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int end1;
                int end2;
                if(grid[i][j] == '/') {
                    // connect (i, j+1) and (i+1, j)
                    end1 = i*(m+1) + j+1;
                    end2 = (i+1)*(m+1) + j;
                } else if(grid[i][j] == '\\') {
                    // connect (i, j) and (i+1, j+1)
                    end1 = i*(m+1) + j;
                    end2 = (i+1)*(m+1) + j+1;
                } else {
                    continue;
                }
                int parentA = getParent(end1);
                int parentB = getParent(end2);
                if(parentA == parentB) {
                    cnt++;
                } else {
                    parent[parentB] = parentA;
                }
            }
        }

        return cnt;
    }
};
