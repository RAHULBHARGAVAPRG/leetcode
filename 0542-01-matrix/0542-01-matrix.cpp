class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
queue<pair<pair<int,int>,int>> q;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
         q.push({{i,j},0});
         vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int row= q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        ans[row][col]=steps;
            int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int i =0;i<4;i++){
        int r = row+dr[i];
        int c= col+dc[i];
        if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0){
            vis[r][c]=1;
            q.push({{r,c},steps+1});
        }
    }
    }
return ans;


    }
};