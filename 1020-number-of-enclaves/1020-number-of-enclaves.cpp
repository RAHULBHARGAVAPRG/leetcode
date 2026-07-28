class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& vis, vector<int> &dr, vector<int> &dc) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int r = row + dr[i];
            int c = col + dc[i];
            if (r < n && r >= 0 && c >= 0 && c < m && !vis[r][c] &&
                grid[r][c] == 1) {
                dfs(grid, r, c, vis, dr, dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
                int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dr= {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
                for (int i = 0; i < m; i++) {
            if (!vis[0][i] && grid[0][i] == 1) {
                dfs(grid, 0, i, vis, dr, dc);
            }
            if (!vis[n - 1][i] && grid[n - 1][i] == 1) {
                dfs(grid, n - 1, i, vis, dr, dc);
            }
        }
        for (int j = 0; j < n; j++) {
            if (!vis[j][0] && grid[j][0] == 1) {
                dfs(grid, j, 0, vis, dr, dc);
            }
            if (!vis[j][m - 1] && grid[j][m - 1] == 1) {
                dfs(grid, j, m - 1, vis, dr, dc);
            }
        }
        int count =0;
                for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                   count++;
                }
            }
        }
        return count ;
    }
};