class Solution {
public:
    double distance(int x, int y, vector<int>& target) {
        return abs(y - target[1]) + abs(x - target[0]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        double compare = distance(0, 0, target);
        for (int x = 0; x < ghosts.size(); ++x) {
            if (distance(ghosts[x][0], ghosts[x][1], target) <= compare) {
                return false;
            }
        }
        return true;
    }
};