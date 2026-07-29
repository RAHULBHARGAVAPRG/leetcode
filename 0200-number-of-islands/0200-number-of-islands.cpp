class Solution {
public:
void dfs(vector<vector<char>> &grid, int row,int col , vector<vector<char>> &vis){
 vis[row][col]=1;
 int n = grid.size();
int m = grid[0].size();
 vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};
for(int i =0;i<4;i++){
    int r = dr[i]+ row ;
    int c = dc[i] + col;
    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]=='1'){
        dfs(grid,r,c,vis);
    }
}
 
}
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<char >>  vis(n, vector<char>(m, 0)) ;
       int count=0;
       for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]== '1' && !vis[i][j]){
                count ++;
                dfs(grid,i,j,vis);
            }
        }
       } 
       return count ;
    }
};