class DSU {
    vector<int> par, rnk;
    public:
    DSU(int n) {
        par.assign(n, 0);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        rnk.assign(n, 0);
    }

    int find(int x) {
        if(x == par[x]) return x;

        return par[x] = find(par[x]);
    }

    bool uni(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if(p1 == p2) return false;

        if(rnk[p1] < rnk[p2]) swap(p1, p2);
        if(rnk[p1] == rnk[p2]) {
            par[p2] = p1;
            rnk[p1]++;
        }
        else {
            par[p2] = p1;
        }
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 2);

        for(auto it : edges) {
            if(!dsu.uni(it[0], it[1])) return it;
        }
        return {};
    }
};
