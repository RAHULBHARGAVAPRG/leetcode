class Solution {
public:
void dfs(vector<vector<int>>& image,int orgcolor,int sr,int sc,int color ){
image[sr][sc]=color;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
       for(int i =0 ; i< 4 ;i++){
        int r = sr + dr[i];
        int c= sc+ dc[i];
        if(r>=0 && r<image.size() && c>=0 && c<image[0].size() && image[r][c]==orgcolor){
            dfs(image ,orgcolor,r,c,color);
        }
       }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int orgcolor=image[sr][sc];
       if(orgcolor==color){
        return image;
       }
       dfs(image,orgcolor,sr,sc,color);

       return image; 
    }
};