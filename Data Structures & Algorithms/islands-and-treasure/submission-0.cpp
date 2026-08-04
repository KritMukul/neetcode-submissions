class Solution {
    void dfs(int x, int y, vector<vector<int>>& grid, int d) {
        if(d >= grid[x][y]) return;
        grid[x][y] = d;
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        for(int i= 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) dfs(nx, ny, grid, d+1);
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    pq.push({0, i, j});
                }
                while(!pq.empty()) {
                    auto [d, x, y] = pq.top();
                    pq.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(grid[nx][ny] > d+1) {
                            grid[nx][ny] = d+1;
                            pq.push({d+1, nx, ny});
                        }
                    }
                }
            }
        }
    }
};
