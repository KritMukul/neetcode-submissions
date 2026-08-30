class Solution {
    bool dfs(int x, vector<bool> &vis, vector<bool>& pvis, vector<vector<int>>& adj) {
        vis[x] = true;
        pvis[x] = true;
        for(auto it : adj[x]) {
            if(vis[it] && pvis[it]) return true;
            else if(!vis[it]) {
                if(dfs(it, vis, pvis, adj)) return true;
            }
            
        }
        pvis[x] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it[1]].emplace_back(it[0]);

        }
        vector<bool> vis(numCourses, false), pvis(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pvis, adj)) return false;
            }
        }
        return true;
    }
};
