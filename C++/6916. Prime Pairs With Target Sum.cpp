class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n + 1, 1);
        for (int x = 2; x <= n; ++x) {
            if (!prime[x]) {
                continue;
            }
            else {
                for (int y = 2 * x; y <= n; y += x) {
                    prime[y] = 0;
                }
            }
        }
        vector<vector<int>> ans;
        for (int x = 2; x <= n / 2; ++x) {
            if (prime[x] && prime[n - x]) {
                ans.push_back({x, n - x});
            }
        }
        return ans;
    }
};