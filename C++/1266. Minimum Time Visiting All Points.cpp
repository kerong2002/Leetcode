class Solution {
public:
    int cal(int y1, int x1, int y2, int x2) {
        int y = abs(y1 - y2);
        int x = abs(x1 - x2);
        return max(x, y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int ans = 0;
        for (int y = 0; y < points.size() - 1; ++y) {
            ans += cal(points[y][0], points[y][1], points[y + 1][0], points[y + 1][1]);
        }
        return ans;
    }
};