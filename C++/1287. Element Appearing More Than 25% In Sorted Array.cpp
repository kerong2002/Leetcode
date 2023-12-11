class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int m25 = arr.size() / 4;
        vector<int> dp(arr[arr.size()- 1] + 1, 0);
        for (int x = 0; x < arr.size(); ++x) {
            ++dp[arr[x]];
            if (dp[arr[x]] > m25)  {
                return arr[x];
            }
        }
        return 0;
    }
};