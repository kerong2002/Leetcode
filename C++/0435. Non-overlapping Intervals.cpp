class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int last = 0;

        for (int y = 1; y < intervals.size(); ++y) {
            if (intervals[y][0] >= intervals[last][1]) {
               last = y;
            }
            else {
                ans++;
                if (intervals[y][1] < intervals[last][1]) {
                    last = y;
                }
            }
        }
        return ans;
    }
};