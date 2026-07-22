class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0)
            return 0;

        int minutes = 0;

        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){

            int size = q.size();
            bool rotted = false;   

            for(int i = 0; i < size; i++){

                pair<int,int> curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(int k = 0; k < 4; k++){

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < row &&
                       nc >= 0 && nc < col &&
                       grid[nr][nc] == 1){

                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;     
                    }
                }
            }

            if(rotted)              
                minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};