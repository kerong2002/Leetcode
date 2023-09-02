class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() + 1, 0);
        int dSize = dictionary.size();
        for (int y = 1; y <= s.size(); ++y) {
            dp[y] = dp[y - 1] + 1;
            for (int x = 0; x < dSize; ++x) {
                int wordSize = dictionary[x].size();
                if (y - wordSize < 0) {
                    continue;
                }
                string temp = s.substr(y - wordSize, wordSize);
                int find = temp.find(dictionary[x]);
                if (find != string::npos) {
                    dp[y] = min(dp[y], dp[y - wordSize]);
                }
            }
        }
        return dp[s.size()];
    }
};