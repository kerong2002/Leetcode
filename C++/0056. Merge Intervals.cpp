class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int x = 0; x < size; ++x) {
            if (ans.empty() || ans.back()[1] < intervals[x][0]) {
                ans.push_back({intervals[x][0], intervals[x][1]});
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[x][1]);
            }
        }
        return ans;
    }
};