class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for (auto y : matrix) {
            for (auto x : y) {
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};