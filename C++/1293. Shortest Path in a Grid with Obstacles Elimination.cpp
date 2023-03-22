struct cube_data{
    int step;
    int k;
    int x;
    int y;
    cube_data(): step(0), k(0), x(0), y(0){}
};

//========<上右下左>==========
int dx[4] = {  0, 1,  0, -1};
int dy[4] = { -1, 0,  1,  0};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> visited(row, vector<vector<int>>(col, vector<int>(k+1, 0)));
        cube_data *node = new cube_data();
        queue<cube_data *> q;
        node->k = k;
        //========<把起始位置丟入佇列>=========
        q.push(node);
        
        int ans = -1;
        while(!q.empty()){
            //===========<走到終點>============
            if(q.front()->x == col-1 && q.front()->y == row-1){
                ans = q.front()->step;
                break;
            }
            //==========<嘗試探索>==========
            for(int t=0;t<4;t++){
                //============<邊界設定>=============
                if(q.front()->x + dx[t] >=0 && q.front()->x + dx[t] < col && q.front()->y + dy[t] >=0 && q.front()->y + dy[t] < row){
                    cube_data *temp = new cube_data();
                    temp->x = q.front()->x + dx[t];
                    temp->y = q.front()->y + dy[t];
                    temp->step = q.front()->step + 1;
                    if(grid[temp->y][temp->x]==0 && !visited[temp->y][temp->x][q.front()->k]){
                        visited[temp->y][temp->x][q.front()->k] = 1;
                        temp->k = q.front()->k;
                        q.push(temp);
                    }
                    if(grid[temp->y][temp->x]==1 && q.front()->k>0 && !visited[temp->y][temp->x][q.front()->k-1]){
                        visited[temp->y][temp->x][q.front()->k -1] = 1;
                        temp->k = q.front()->k - 1;
                        q.push(temp);
                    }
                }
            }
            //=========<把頭丟掉>===========
            q.pop();
        }
        return ans;
    }
};