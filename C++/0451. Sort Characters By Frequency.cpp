class Solution {
public:
    string frequencySort(string s) {
        vector<int> ascii(75, 0);
        int maxFreq = 0;
        for(auto ss : s) {
            ++ascii[ss - '0'];
            maxFreq = max(maxFreq, ascii[ss - '0']);
        }
        string ans;
        for (int y = maxFreq; y >= 1; --y) {
            for (int x = 0; x < 75; ++x) {
                if(ascii[x] == y) {
                    for(int t = 0; t < y; ++t) {
                        ans.push_back(x + '0');
                    }
                }
            }
        }
        return ans;
    }
};