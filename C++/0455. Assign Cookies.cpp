class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0;
        int p = 0;
        int ans = 0;
        while (c < s.size() && p < g.size()) {
            if (g[p] <= s[c]) {
                ++ans;
                ++p;
                ++c;
            }
            else {
                ++c;
            }
        }
        return ans;
    }
};