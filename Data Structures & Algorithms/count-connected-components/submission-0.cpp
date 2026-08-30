class Solution {
    void dfs(int x, vector<vector<int>> & adj, vector<bool> & vis) {
        vis[x] = true;

        for(auto it : adj[x]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i =0; i < n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};
