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
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            
            if(!vis[i]){if(dfs(0, -1, adj, vis)) return false;}
            
        }
        return true;
    }
};
