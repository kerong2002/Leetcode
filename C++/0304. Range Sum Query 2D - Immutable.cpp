class NumMatrix {
public:
    vector<vector<int>> graph;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        graph.resize(row, vector<int>(col, 0));
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                graph[y][x] = matrix[y][x];
                if(y>0) graph[y][x] += graph[y-1][x];
                if(x>0) graph[y][x] += graph[y][x-1];
                if(x>0 && y>0) graph[y][x] -= graph[y-1][x-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans = graph[row2][col2];
        if(row1>0) ans -= graph[row1-1][col2];
        if(col1>0) ans -= graph[row2][col1-1];
        if(col1>0 && row1>0) ans += graph[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */