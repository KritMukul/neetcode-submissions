class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for(auto it : points) {
            int x = it[0], y = it[1];
            int d = x*x + y*y;
            pq.push({d, it});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()) {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
