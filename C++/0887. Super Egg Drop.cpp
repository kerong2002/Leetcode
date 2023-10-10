class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (k == 1) {
            return n;
        }
        vector<vector<int>> dp(k + 1, vector<int> (n + 1, 0));
        for (int y = 1; y <= k; ++y) {
            dp[y][1] = 1;
        }
        for (int x = 1; x <= n; ++x) {
            dp[1][x] = x;
        }
        for (int y = 2; y <= k; ++y) {
            for (int x = 2; x <= n; ++x) {
                int L = 1;
                int R = x;
                int temp = 0;
                int ans = 1e6;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    int b = dp[y - 1][mid - 1];
                    int nb = dp[y][x - mid];
                    temp = max(b, nb) +  1;
                    if (b < nb) {
                        L = mid + 1;
                    }
                    else {
                        R = mid - 1;
                    }
                    ans = min(ans, temp);
                }
                dp[y][x] = ans;
            }
        }

        return dp[k][n];
    }
};