class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> um;
        int x = 0;
        int y = 0;
        um[{x, y}] = false;
        for (auto c : path) {
            if (c == 'N') {
                y += 1;
            }
            else if (c == 'E') {
                x += 1;
            }
            else if (c == 'S') {
                y -= 1;
            }
            else if (c == 'W') {
                x -= 1;
            }
            if (um.count({x, y})) {
                return true;
            }
            um[{x, y}] = true;
        }
        return false;
    }
};