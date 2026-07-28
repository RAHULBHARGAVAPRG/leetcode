class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col,
             vector<vector<int>>& vis, vector<int> &dr, vector<int> &dc) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int r = row + dr[i];
            int c = col + dc[i];
            if (r < n && r >= 0 && c >= 0 && c < m && !vis[r][c] &&
                board[r][c] == 'O') {
                dfs(board, r, c, vis, dr, dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dr= {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(board, 0, i, vis, dr, dc);
            }
            if (!vis[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(board, n - 1, i, vis, dr, dc);
            }
        }
        for (int j = 0; j < n; j++) {
            if (!vis[j][0] && board[j][0] == 'O') {
                dfs(board, j, 0, vis, dr, dc);
            }
            if (!vis[j][m - 1] && board[j][m - 1] == 'O') {
                dfs(board, j, m - 1, vis, dr, dc);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    };