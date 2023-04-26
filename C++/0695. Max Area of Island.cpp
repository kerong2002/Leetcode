class Solution {
public:
    void dfs(vector<vector<int>>& grid, int y, int x, int *area){
        if(y<0 || y>=grid.size() || x<0 || x>=grid[0].size() || grid[y][x]==0){
            return;
        }
        else{
            grid[y][x] = 0;
            (*area) += 1;
            dfs(grid, y-1, x  , area);
            dfs(grid, y  , x+1, area);
            dfs(grid, y+1, x  , area);
            dfs(grid, y  , x-1, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                if(grid[y][x] == 1){
                    int area = 0;
                    dfs(grid, y, x, &area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};