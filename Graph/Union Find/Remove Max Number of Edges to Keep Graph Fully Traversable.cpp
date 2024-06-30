//T.C : O(n)
//S.C : O(n)
class UnionFind{
    public:
    vector<int> rank;
    vector<int> par;

    UnionFind(int n)
    {
        rank.assign(n, -1);
        par.assign(n, -1);
        for(int i = 0; i<n; i++)
        {
            par[i] = i;
        }
    }

    int find(int x)
    {
        if(x == par[x])
        {
            return x;
        }
        else
        {
            return par[x] = find(par[x]);
        }
    }

    bool merge(int x, int y)
    {
        if(find(x) == find(y))
        {
            return false;
        }
        else
        {
            x = find(x);
            y = find(y);

            if(rank[x] >= rank[y])
            {
                rank[x] += rank[y];
                par[y] = x;
            }
            else
            {
                rank[y] += rank[x];
                par[x] = y;
            }

            return true;
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int removed = 0;
        int e1 = 0;
        int e2 = 0;
        UnionFind uf(n);

        for(int i = 0; i<edges.size(); i++)
        {
            if(edges[i][0] == 3)
            {
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;

                if(uf.merge(u, v))
                {
                    e1++;
                    e2++;
                }
                else
                {
                    removed++;
                }
            }
        }

        UnionFind uftemp = uf;

        for(int i = 0; i<edges.size(); i++)
        {
            if(edges[i][0] == 1)
            {
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;

                if(uf.merge(u, v))
                {
                    e1++;
                }
                else
                {
                    removed++;
                }
            }
        }

        uf = uftemp;

        for(int i = 0; i<edges.size(); i++)
        {
            if(edges[i][0] == 2)
            {
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;

                if(uf.merge(u, v))
                {
                    e2++;
                }
                else
                {
                    removed++;
                }
            }
        }

        if(e1 != n-1 || e2 != n-1)
        {
            return -1;
        }
        else
        {
            return removed;
        }
    }
};
