class Solution {
public:
    double cross(vector<vector<int>>& trees, int a, int b, int c) {
        return (trees[b][0] - trees[a][0]) * (trees[c][1] - trees[a][1]) -
               (trees[b][1] - trees[a][1]) * (trees[c][0] - trees[a][0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        sort(trees.begin(), trees.end());
        vector<int> s;
        int maxSize = trees.size();
        vector<bool> used(maxSize, false);

        for (int x = 0; x < maxSize; ++x) {     //lower convex hull
            while (s.size() >= 2 && cross(trees, s[s.size() - 2], s.back(), x) > 0) {
                used[s.back()] = false;
                s.pop_back();
            }
            s.push_back(x);
            used[x] = true;
        }
        used[0] = false;
        for (int x = maxSize - 1; x >= 0; --x) {     //upper convex hull
            if (used[x]){
                continue;
            }
            while (s.size() >= 2 && cross(trees, s[s.size() - 2], s.back(), x) > 0) {
                s.pop_back();
            }
            s.push_back(x);
        }
        for (int x = 0; x < s.size() - 1; ++x) {
           ans.push_back(trees[s[x]]);
        }
        return ans;
    }
};