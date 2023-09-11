class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> v(501);
        int max_size = 0;
        for (int x = 0; x < groupSizes.size(); ++x) {
            v[groupSizes[x]].push_back(x); 
            max_size = max(max_size, groupSizes[x]);
        }
        vector<vector<int>> ans;
        for (int y = 1; y <= max_size; ++y) {
            if (v[y].size() > 0) {
                vector<int> temp;
                for (int x = 0; x < v[y].size(); ++x) {
                    if (temp.size() >= y) {
                        ans.push_back(temp);
                        temp.clear();
                    }
                    temp.push_back(v[y][x]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};