class Solution {
    void dfs(int x, int y, vector<vector<char>> & grid, vector<vector<bool>> & vis) {
        vis[x][y] = true;
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1' && !vis[nx][ny])dfs(nx, ny, grid, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int c = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    c++;
                }
            }
        }
        return c;
    }
};
