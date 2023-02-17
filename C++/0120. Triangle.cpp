class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row].size();
        for(int y=row-2;y>=0;y--){
            for(int x=y;x>=0;x--){
                triangle[y][x] += min(triangle[y+1][x], triangle[y+1][x+1]);
            }
        }
        return triangle[0][0];
    }
};