class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (auto x : nums) {
            ans.push_back(pow(x, 2));
        }
        for (int i = 0; i< ans.size(); ++i) {
            if (i % 2 == 0) {
                for (int x = 0; x < ans.size() - 1; x += 2) {
                    if (ans[x] > ans[x + 1]) {
                        swap(ans[x], ans[x + 1]);
                    }
                }
            }
            else {
                for (int x = 1; x < ans.size() - 1; x += 2) {
                    if (ans[x] > ans[x + 1]) {
                        swap(ans[x], ans[x + 1]);
                    }
                }
            }
        }
        return ans;
    }
};