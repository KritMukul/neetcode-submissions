class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);


        for(auto it : times) {
            adj[it[0]].emplace_back(it[1], it[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n + 1, 1e9);
        pq.emplace(0, k);
        time[k] = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int t = p.first, x = p.second;

            for(auto it : adj[x]) {
                if(time[x] + it.second < time[it.first]) {
                    time[it.first] = time[x] + it.second;
                    pq.emplace(it.second, it.first);
                }
            }
        }
        int ans = *max_element(time.begin() + 1, time.end());
        return ans == 1e9 ? -1 : ans;
    }
};
