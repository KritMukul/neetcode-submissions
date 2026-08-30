class DSU {
    vector<int> parent, rank;
    int comps;
    public:

    DSU(int n) {
        comps = n;
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n);
    }

    int findUPar(int x) {
        if(parent[x] == x) return x;

        return parent[x] = findUPar(parent[x]);
    }

    bool uni(int x, int y) {
        int par1 = findUPar(x), par2 = findUPar(y);
        if(par1 == par2) return false;
        comps--;
        if(rank[par1] == rank[par2]) {
            parent[par2] = par1;
            rank[par1]++;
        }
        else if(rank[par1] < rank[par2]) {
            parent[par1] = par2;
        }
        else parent[par2] = par1;
        return true;
    }
    int compo() {
        return comps;
    }
};

class Solution {
    bool dfs(int x, int par, vector<vector<int>> & adj, vector<bool> & vis) {
        vis[x] = true;
        for(auto it : adj[x]) {\
            if(it == par) continue;
            if(vis[it]) return true;
            if(dfs(it, x, adj, vis)) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if(edges.size() != n-1) return false;
        // vector<vector<int>> adj(n);
        // for(auto it : edges) {
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        // vector<bool> vis(n, false);
        // for(int i = 0; i < n; i++) {
            
        //     if(!vis[i]){if(dfs(0, -1, adj, vis)) return false;}
            
        // }
        // return true;

        if(edges.size() > n-1) return false;

        DSU dsu(n);
        for(auto & edge : edges) {
            if(!dsu.uni(edge[0], edge[1])) return false;
        }
        return dsu.compo() == 1;
    }
};
