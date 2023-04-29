class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        int FreshOrange = 0;
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                if(grid[y][x] == 2){
                    q.push({y, x});
                }
                else if(grid[y][x] == 1){
                    FreshOrange++;
                }
            }
        }
        if(FreshOrange == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int minutes = -1;
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int t=0;t<4;t++){
                    int i = y + dir[t].first;
                    int j = x + dir[t].second;
                    if(i >= 0 && j >= 0 && i < row && j < col  && grid[i][j]==1){
                        grid[i][j] = 2;
                        FreshOrange--;
                        q.push({i,j});
                    }
                }
            }
            minutes++;
        }
        return ((!FreshOrange) ? minutes : -1 );
    }
};