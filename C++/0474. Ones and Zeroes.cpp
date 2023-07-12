class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs){
            int zero = 0;
            int one = 0;
            for (char c : str) {
                    if(c == '0') {
                        ++zero;
                    }
                    else{
                        ++one;
                    }
            }
            for (int y = m; y >= zero; --y) {
                for (int x = n; x >= one; --x) {
                    dp[y][x] = max(dp[y][x], dp[y - zero][x - one] + 1);              
                }
            }
        }
        
        return dp[m][n];
    }
};