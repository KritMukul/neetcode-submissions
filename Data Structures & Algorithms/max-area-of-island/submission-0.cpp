class Solution {
    int dfs(int x, int y, vector<vector<int>> & grid, vector<vector<bool>> & vis) {
        if(vis[x][y]) return 0;
        vis[x][y] = true;
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        int cnt = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) cnt += dfs(nx, ny, grid, vis);
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    maxi = max(maxi, dfs(i, j, grid, vis));
                    
                }
            }
        }
        return maxi;
    }
};



