class Solution {
public:
    void dfs(vector<vector<int>>& image, int y, int x, int color, int pick){
        if(y<0 || x<0 || y>=image.size() || x>=image[0].size() || image[y][x] != pick){
            return;
        }
        else{
            image[y][x] = color;
            dfs(image, y-1, x  , color, pick);
            dfs(image, y  , x+1, color, pick);
            dfs(image, y+1, x  , color, pick);
            dfs(image, y  , x-1, color, pick);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color){
            dfs(image, sr, sc, color, image[sr][sc]);
        }
        return image;
    }
};