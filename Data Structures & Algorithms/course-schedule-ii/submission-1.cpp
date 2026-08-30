class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for(auto it : pre) {
            adj[it[1]].emplace_back(it[0]);
            ind[it[0]]++;
        }

        for(int i = 0; i < n; i++) {
            if(ind[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int x = q.front();
            ans.emplace_back(x);
            q.pop();
            for(auto it : adj[x]) {
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }
        vector<int> v;
        return ans.size() == n ? ans : v;
    }
};
