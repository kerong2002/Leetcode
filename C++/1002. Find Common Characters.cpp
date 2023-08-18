class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> dp(words.size(), vector<int>(26, 0));
        for (int y = 0; y < words.size(); ++y) {
            for (int x = 0; x < words[y].size(); ++x) {
                ++dp[y][words[y][x] - 'a'];
            }
        }
        
        vector<string> ans;
        for (int y = 0; y < 26; ++y) {
            int temp = INT_MAX;
            for (int x = 0; x < words.size(); ++x) {
                temp = min(temp, dp[x][y]);
            }
            for (int x = 0; x < temp; ++x) {
                ans.push_back(string(1, y + 'a'));
            }
        }
        return ans;
    }
};